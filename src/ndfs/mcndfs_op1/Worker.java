package ndfs.mcndfs_op1;

import java.lang.Runnable;
import java.util.HashMap;
import java.util.List;
import java.util.Random;
import java.util.Collections;
import java.util.concurrent.atomic.AtomicInteger;

import graph.Graph;
import graph.State;

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
  private NDFSThreadState threadState;

  // Globals
  private MapWithDefaultValues<State, Boolean> isRed;
  private MapWithDefaultValues<State, AtomicInteger> visitCount;

  public Worker(final Graph graph,
      MapWithDefaultValues<State, Boolean> isRed,
      MapWithDefaultValues<State, AtomicInteger> visitCount,
      long randomSeed,
      State initialState
      )
  {
    // Locals
    this.graph = graph;
    this.colors = new MapWithDefaultValues<State,Color>(new HashMap<State,Color>(),Color.WHITE);
    this.randomSeed = randomSeed;
    this.initialState = initialState;

    // Globals
    this.isRed = isRed;
    this.visitCount  = visitCount;
  }

  public NDFSThreadState getThreadState() {
    return threadState;
  }
  
  public void setThreadState(NDFSThreadState threadState) {
    this.threadState = threadState;
  }
  
  private void dfsRed(State s) throws Result {
    colors.setValue(s, Color.PINK);
  
    List<State> shuffledList = graph.post(s);
    Collections.shuffle(shuffledList, new Random(randomSeed));
      for (State t : shuffledList) {
        if (colors.hasKeyValuePair(t, Color.CYAN)) {
          throw new CycleFound();
        }
        if ( true
             && (!colors.hasKeyValuePair(t, Color.PINK))
             && isRed.hasKeyValuePair(t, false) 
        ){
          dfsRed(t);
        }
      }
      if (s.isAccepting()) {
        visitCount.getValue(s).decrementAndGet();
        while (visitCount.getValue(s).get() != 0){
          // spin
        }
      }
      isRed.setValue(s, true);
    }


  private void dfsBlue(State s) throws Result {
    boolean allRed = true;
    colors.setValue(s, Color.CYAN);
    List<State> shuffledList = graph.post(s);
    Collections.shuffle(shuffledList, new Random(randomSeed));
    for (State t : shuffledList) {
      if( true
        && colors.hasKeyValuePair(t, Color.CYAN)
        && (s.isAccepting() || t.isAccepting())
      ){
          throw new CycleFound();
      }
      if( true
        && colors.hasKeyValuePair(t, Color.WHITE)
        && isRed.hasKeyValuePair(t, false)
      ){
        dfsBlue(t);
      }
      if(isRed.hasKeyValuePair(t, false)){
        allRed = false;
      }
    }
    if(allRed){
      isRed.setValue(s, true);
    }
    else if(s.isAccepting()){
      visitCount.getValue(s).incrementAndGet();
      dfsRed(s);
    }
    colors.setValue(s, Color.BLUE);
  }

  public void run(){
  
    long start = System.currentTimeMillis();
    long end;
 
    threadState = NDFSThreadState.DONE;

    while (true){
      if(Thread.currentThread().isInterrupted()){
        break;
      }
        // wait until master 
        // - assigns task to this thread
        // - master sets threadState to BUSY 
        // in THIS order
      while(threadState== NDFSThreadState.DONE){
      }
      
      try{
        dfsBlue(initialState);
        threadState = NDFSThreadState.DONE; // cycle not found
      }
      catch(Result r){
        threadState = NDFSThreadState.CYCLE_FOUND;
      }
      
    }
  }

}
