package ndfs.mcndfs_alg3;

import java.lang.Runnable;
import java.util.HashMap;
import java.util.List;
import java.util.Random;
import java.util.Collections;
import java.util.concurrent.atomic.AtomicInteger;
import java.util.concurrent.ExecutorService;

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

  // Globals
  private MapWithDefaultValues<State, Boolean> isRed;
  private MapWithDefaultValues<State, AtomicInteger> visitCount;
  private ExecutorService executor;
  
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

    // Globals
    this.isRed = isRed;
    this.visitCount  = visitCount;
    this.executor = executor;
  }

  private void dfsRed(State s) throws Result {
    
    if (Thread.currentThread().isInterrupted()) {
      return;
    }
    
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
        System.out.println("");
        while (visitCount.getValue(s).get() != 0){
          // spin
          System.out.println("dfsRed(): " + visitCount.getValue(s).get() + "hash code: " + s.hashCode());
          if (Thread.currentThread().isInterrupted()) {
            break;
          }
        }
      }
      isRed.setValue(s, true);
    }


  private void dfsBlue(State s) throws Result {
    
    if (Thread.currentThread().isInterrupted()) {
      return;
    }
    
    boolean allRed = true;
    colors.setValue(s, Color.CYAN);
    List<State> shuffledList = graph.post(s);
    Collections.shuffle(shuffledList, new Random(randomSeed));
    for (State t : shuffledList) {
      if( true
        && colors.hasKeyValuePair(t, Color.CYAN)
        && (s.isAccepting() || t.isAccepting())
      ){
          System.out.println("Early");
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
        System.out.println("dfsBlue(): " + visitCount.getValue(s).get() + "hash code : " + s.hashCode());
        try{
        Thread.sleep(5000);
        } catch(InterruptedException ie){}
        
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
    } 
    catch (CycleFound cf) {
      end = System.currentTimeMillis();
      System.out.println(cf.getMessage());
      System.out.printf("%s took %d ms\n", "MC_NDFS", end - start);
      executor.shutdownNow();
    }
    catch (Result r) {
      end = System.currentTimeMillis();
      System.out.println(r.getMessage());
      System.out.printf("%s took %d ms\n", "MC_NDFS", end - start);
      //executor.shutdownNow();
    }
  }

}
