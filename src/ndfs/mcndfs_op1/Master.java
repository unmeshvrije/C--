package ndfs.mcndfs_op1;

import java.util.HashMap;
import java.util.ArrayList;

import java.util.concurrent.atomic.AtomicInteger;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

import graph.State;
import graph.Graph;

import ndfs.NDFS;
import ndfs.Result;
import ndfs.CycleFound;
import ndfs.NoCycleFound;
import ndfs.MapWithDefaultValues;


public class Master implements NDFS {

  private Graph graph;
  private MapWithDefaultValues<State, Boolean> isRed;
  private MapWithDefaultValues<State, AtomicInteger> visitCount;
  private int nThreads;
  
  private int depth;
  private ArrayList<State> tasks; // Queue of "initial" states
  private ArrayList<Worker> workerList;
  
  
  public Master(Graph graph, int nThreads, int depth){
    this.graph = graph;
    this.isRed = new MapWithDefaultValues<State, Boolean>(new HashMap<State, Boolean>(), false);
    this.visitCount = new MapWithDefaultValues<State, AtomicInteger>(new HashMap<State, AtomicInteger>(), new AtomicInteger(0));
    this.nThreads = nThreads;
    this.depth = depth;
    this.tasks = new ArrayList<State>();
    this.workerList = new ArrayList<Worker>();
  }

  public void init(){
    // do nothing
  }

  private long getRandomSeed(Integer i) {
    return System.currentTimeMillis() + (i * 179);
  }

  private void bfs(){
    ArrayList<State> states = new ArrayList<State>();
    
    this.tasks.add(graph.getInitialState());
    
    for(int d = 0; d < this.depth; d++){
      for(State t: tasks){
        states.addAll(graph.post(t));
      }
      tasks = states;
    }
  
  }

  private void nndfs(State s) throws Result {
  
    // Create tasks
    try {
      bfs();
    } catch (OutOfMemoryError e) {
      System.out.println(e.toString());
      System.exit(1);
    }
        
    
    ExecutorService executor = Executors.newFixedThreadPool(nThreads);
    
    // Hand out tasks for all worker-threads until work-queue is empty
    for(int index = 0; index < nThreads; index++){
    
      if(!tasks.isEmpty()) {
        break;
      }
      
      workerList.set(index, new Worker(graph, isRed, visitCount, getRandomSeed(index), tasks.remove(tasks.size() - 1)));
      executor.execute(workerList.get(index));
      
      Worker temp = workerList.get(index);
      temp.setThreadState(NDFSThreadState.BUSY);
    }
    
    while(true){
      // If there are still tasks in the work queue, then wait for threads to finish
      for (int index = 0; index < nThreads; ++index) {
      
        NDFSThreadState threadState = workerList.get(index).getThreadState();
        switch (threadState) {
          case DONE: {
            workerList.set(index, new Worker(graph, isRed, visitCount, getRandomSeed(index), tasks.remove(tasks.size() - 1)));
            executor.execute(workerList.get(index));
            
            //TODO: proper casting
            Worker temp = workerList.get(index);
            temp.setThreadState(NDFSThreadState.BUSY);
            
            break;
          }
          case BUSY: {
            // Nothing
            break;
          }
          case CYCLE_FOUND: {
            executor.shutdown();
            return;
          }
        } //switch
      } //for
    } // while
  }

  public void ndfs() throws Result {
    nndfs(graph.getInitialState());
  }
}
