package ndfs.mcndfs_alg3;

import java.util.HashMap;
import java.util.concurrent.atomic.AtomicInteger;

import graph.State;
import graph.Graph;

import ndfs.NDFS;
import ndfs.Result;
import ndfs.CycleFound;
import ndfs.NoCycleFound;
import ndfs.MapWithDefaultValues;


public class NNDFS implements NDFS {

  private Graph graph;
  private MapWithDefaultValues<State, Boolean> isRed;
  private MapWithDefaultValues<State, AtomicInteger> visitCount;
  private int nThreads;
  
  public NNDFS(Graph graph, int nThreads){
    this.graph = graph;
    this.isRed = new MapWithDefaultValues<State, Boolean>(new HashMap<State, Boolean>(), false);
    this.visitCount = new MapWithDefaultValues<State, AtomicInteger>(new HashMap<State, AtomicInteger>(), new AtomicInteger(0));
    this.nThreads = nThreads;
  }

  public void init(){
    // do nothing
  }

  private long getRandomSeed(Integer i) {
    return System.currentTimeMillis() + (i * 179);
  }

  private void nndfs(State s) throws Result {
    // Create threads here
    Worker[] worker = new Worker[nThreads];

    try{
      for (int i = 0; i < nThreads; ++i){
        worker[i] = new Worker(graph, isRed, visitCount, getRandomSeed(i));
        worker[i].run();
      }
    } catch (Exception e) {
      //e.prIntegerStackTrace();
      System.out.println("Our Exception");
    }
  }

  public void ndfs() throws Result {
    nndfs(graph.getInitialState());
  }
}
