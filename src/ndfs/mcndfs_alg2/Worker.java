package ndfs.mcndfs_alg2;

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
  private MapWithDefaultValues<State,Boolean> isPink;
  private long randomSeed;

  // Globals
  private MapWithDefaultValues<State, Boolean> isRed;
  private MapWithDefaultValues<State, AtomicInteger> visitCount;

  public Worker(final Graph graph,
      MapWithDefaultValues<State, Boolean> isRed,
      MapWithDefaultValues<State, AtomicInteger> visitCount,
      long randomSeed)
  {
    // Locals
    this.graph = graph;
    this.colors = new MapWithDefaultValues<State,Color>(new HashMap<State,Color>(),Color.WHITE);
    this.isPink = new MapWithDefaultValues<State,Boolean>(new HashMap<State,Boolean>(), false);
    this.randomSeed = randomSeed;

    // Globals
    this.isRed = isRed;
    this.visitCount  = visitCount;
  }

  private void dfsRed(State s) throws Result {
    isPink.setValue(s, true);
  
    List<State> shuffledList = graph.post(s);
    Collections.shuffle(shuffledList, new Random(randomSeed));
      for (State t : shuffledList) {
        if (colors.hasKeyValuePair(t, Color.CYAN)) {
          throw new CycleFound();
        }
        if ( true
             && isPink.hasKeyValuePair(t, false) 
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
      isPink.setValue(s, false);
    }


  private void dfsBlue(State s) throws Result {
    colors.setValue(s, Color.CYAN);
    List<State> shuffledList = graph.post(s);
    Collections.shuffle(shuffledList, new Random(randomSeed));
    for (State t : shuffledList) {
      if( true
        && colors.hasKeyValuePair(t, Color.WHITE)
        && isRed.hasKeyValuePair(t, false)
      ){
        dfsBlue(t);
      }
    }
    if(s.isAccepting()){
      visitCount.getValue(s).incrementAndGet();
      dfsRed(s);
    }
    colors.setValue(s, Color.BLUE);
  }

  public void run(){
  
    long start = System.currentTimeMillis();
    long end;
    
    try {
      dfsBlue(graph.getInitialState());
      throw new NoCycleFound();
    } catch (Result r) {
      end = System.currentTimeMillis();
      System.out.println(r.getMessage());
      System.out.printf("%s took %d ms\n", "MC_NDFS", end - start);
    }
  }

}
