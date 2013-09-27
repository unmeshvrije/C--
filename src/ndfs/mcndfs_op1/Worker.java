package ndfs.mcndfs_op1;

import java.lang.Runnable;
import java.util.HashMap;
import java.util.List;
import java.util.Random;
import java.util.Collections;
import java.util.concurrent.atomic.AtomicInteger;
import java.util.concurrent.ExecutorService;
import java.util.Stack;
import java.util.Queue;

import java.io.File;
import java.io.FileNotFoundException;


import graph.State;
import graph.Graph;
import graph.GraphFactory;

import ndfs.Result;
import ndfs.CycleFound;
import ndfs.NoCycleFound;
import ndfs.MapWithDefaultValues;
import ndfs.Color;

class Worker implements Runnable
{
  // Locals
  private final Graph graph;
  private MapWithDefaultValues<State,Color> colors;
  private long randomSeed;
  private State initialState;
  private ExecutorService executor;

  // Globals
  private MapWithDefaultValues<State, Boolean> isRed;
  private MapWithDefaultValues<State, AtomicInteger> visitCount;

  public Worker(File file,
      MapWithDefaultValues<State, Boolean> isRed,
      MapWithDefaultValues<State, AtomicInteger> visitCount,
      long randomSeed,
      ExecutorService executor
      )
  { 
    // create local reference to prevent (invalid) compiler complaints
    Graph graph = null;
    
    try{
      graph = GraphFactory.createGraph(file);
    } catch(FileNotFoundException e){
      System.out.println("Could not open file");
      System.exit(1);
    }
    
    this.graph = graph;
    
    this.colors = new MapWithDefaultValues<State,Color>(new HashMap<State,Color>(),Color.WHITE);
    this.randomSeed = randomSeed;
    this.initialState = initialState;

    // Globals
    this.isRed = isRed;
    this.visitCount  = visitCount;
    this.executor = executor;
  }

  private void dfsRed(State s) throws Result {

    Stack<State> stack = new Stack<State>();    
    stack.push(s);

    State state;

    while (!stack.isEmpty()) {
      if (Thread.currentThread().isInterrupted()) {
        return;
      }
      state = stack.pop();
      colors.setValue(state, Color.PINK);
    
      List<State> shuffledList = graph.post(state);
      Collections.shuffle(shuffledList, new Random(randomSeed));
      for (State t : shuffledList) {
        if (colors.hasKeyValuePair(t, Color.CYAN)) {
          throw new CycleFound();
        }
        if ( true
             && (!colors.hasKeyValuePair(t, Color.PINK))
             && isRed.hasKeyValuePair(t, false) 
        ){
          stack.push(t);
        }
      }
      if (state.isAccepting()) {

        visitCount.getValue(state).decrementAndGet();
        //visitCount.getValue(state).getAndDecrement();
        while (visitCount.getValue(state).get() != 0){
          // spin
          if (Thread.currentThread().isInterrupted()) {
            break;
          }
          
         //System.out.println("dfsRed(): " + visitCount.getValue(state).get() + "hash code: " + state.hashCode());
        }
      }
      isRed.setValue(state, true);
    }
  }

  private void dfsBlue(State s) throws Result {

    if (Thread.currentThread().isInterrupted()) {
      return;
    }

    Stack<State> stack = new Stack<State>();
    stack.push(s);
    State state;

    while (!stack.isEmpty()){
      state = stack.pop();

      boolean allRed = true;
      boolean whiteChild = false;
      colors.setValue(state, Color.CYAN);
      List<State> shuffledList = graph.post(state);
      Collections.shuffle(shuffledList, new Random(randomSeed));
      for (State t : shuffledList) {
        if( true
          && colors.hasKeyValuePair(t, Color.CYAN)
          && (state.isAccepting() || t.isAccepting())
        ){
            throw new CycleFound();
        }
        if( true
          && colors.hasKeyValuePair(t, Color.WHITE)
          && isRed.hasKeyValuePair(t, false)
        ){
          stack.push(state);
          stack.push(t);
          whiteChild = true;
          break;
        }
        if(isRed.hasKeyValuePair(t, false)){
          allRed = false;
        }
      }
      
      if (whiteChild) {
        continue;
      }
      
      state = stack.pop();
      if(allRed){
        isRed.setValue(state, true);
      }
      else if(state.isAccepting()){
        visitCount.getValue(state).incrementAndGet();
        dfsRed(state);
      }
      colors.setValue(state, Color.BLUE);
    }
  }

  public void run(){
    long start = System.currentTimeMillis();
    long end;
    
    try {
      dfsBlue(graph.getInitialState());
      throw new NoCycleFound();
    } catch (CycleFound cf) {
      end = System.currentTimeMillis();
      System.out.println(cf.getMessage());
      System.out.printf("%s took %d ms\n", "MC_NDFS", end - start);
      executor.shutdownNow();
    }
    catch (Result r) {
      end = System.currentTimeMillis();
      System.out.println(r.getMessage());
      System.out.printf("%s took %d ms\n", "MC_NDFS", end - start);
    }
  }

}
