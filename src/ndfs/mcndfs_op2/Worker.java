package ndfs.mcndfs_op2;

import java.lang.Runnable;
import java.util.HashMap;
import java.util.List;
import java.util.Random;
import java.util.BitSet;
import java.util.Collections;
import java.util.ArrayList;
import java.util.concurrent.atomic.AtomicInteger;
import java.util.concurrent.ExecutorService;

import java.io.File;
import java.io.FileNotFoundException;

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
  private final NDFSGraph ndfsGraph;
  private MapWithDefaultValues<NDFSState,Color> colors;
  private long randomSeed;

  // Globals
  private BitSet isRed;
  private MapWithDefaultValues<NDFSState, AtomicInteger> visitCount;
  private ExecutorService executor;
  
  public Worker(File file,
      BitSet isRed,
      MapWithDefaultValues<NDFSState, AtomicInteger> visitCount,
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
    
    NDFSGraph ndfsGraph = null;
    
    try {
      ndfsGraph = new NDFSGraph(graph, 0);
      ndfsGraph.getAllStates();
      ndfsGraph.permuteSuccessors(randomSeed);
      // we get here
    } catch (OutOfMemoryError oe) {
      System.out.println("Not enough memory!");
      System.exit(1);
    }
    
    this.ndfsGraph = ndfsGraph;
    
    this.colors = new MapWithDefaultValues<NDFSState,Color>(new HashMap<NDFSState,Color>(),Color.WHITE);
    
    System.out.println("hi 1");
 
    
    this.randomSeed = randomSeed;
    

    // Globals
    this.isRed = isRed;
    this.visitCount  = visitCount;
    this.executor = executor;

    System.out.println("hi 2");

  }

  private void dfsRed(NDFSState s) throws Result {
    
    if (Thread.currentThread().isInterrupted()) {
      return;
    }
    
    colors.setValue(s, Color.PINK);
    
    // Use the cached successors
      for (NDFSState t : s.post("asdf")) {
        if (colors.hasKeyValuePair(t, Color.CYAN)) {
          throw new CycleFound();
        }
        if ( true
             && (!colors.hasKeyValuePair(t, Color.PINK))
             && (!isRed.get((int)t.getUniqueIndex()))
        ){
          dfsRed(t);
        }
      }
      if (s.isAccepting()) {
        visitCount.getValue(s).decrementAndGet();
        while (visitCount.getValue(s).get() != 0){
          // spin
          if (Thread.currentThread().isInterrupted()) {
            break;
          }
        }
      }
      
      isRed.set((int)s.getUniqueIndex());
   }


  private void dfsBlue(NDFSState s) throws Result {
      
    System.out.println("dfs blue start");
    if (Thread.currentThread().isInterrupted()) {
      return;
    }
    System.out.println("huh");
    
    boolean allRed = true;
    colors.setValue(s, Color.CYAN);
    System.out.println("huh what");
    
    final List<NDFSState> spost = s.post("dfsBlue:");
    System.out.printf("spost.size() = %d\n",spost.size());
      
    
    
    for (NDFSState t : spost) {
      System.out.println("line 134");
      System.out.printf("index = %d\n",t.getUniqueIndex());
      
      if( true
        && colors.hasKeyValuePair(t, Color.CYAN)
        && (s.isAccepting() || t.isAccepting())
      ){
          throw new CycleFound();
      }
      if( true
        && colors.hasKeyValuePair(t, Color.WHITE)
        && (!isRed.get((int)t.getUniqueIndex()))
      ){
        System.out.println("line 147");
        dfsBlue(t);
        System.out.println("wtf");
      }
      if(!isRed.get((int)t.getUniqueIndex())){
        allRed = false;
      }
    }
    System.out.println("line 154");
    if(allRed){
      isRed.set((int)s.getUniqueIndex());
    }
    else if(s.isAccepting()){
      visitCount.getValue(s).incrementAndGet();
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
      System.out.println("hi 3");
      NDFSState initial = ndfsGraph.getInitialState();
      System.out.println("hi 3.5");
      dfsBlue(initial);
      System.out.println("hi 4");
      throw new NoCycleFound();
    } 
    catch (CycleFound cf) {
      System.out.println("hi 5");
    end = System.currentTimeMillis();
      System.out.println(cf.getMessage());
      System.out.printf("%s took %d ms\n", "MC_NDFS", end - start);
      executor.shutdownNow();
    }
    catch (Result r) {
      System.out.println("hi 6");
      end = System.currentTimeMillis();
      System.out.println(r.getMessage());
      System.out.printf("%s took %d ms\n", "MC_NDFS", end - start);
    }
    System.out.println("thread done");
  }

}
