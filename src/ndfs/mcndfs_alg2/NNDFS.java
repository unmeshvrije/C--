package ndfs.mcndfs_alg2;

import java.util.HashMap;
import java.util.concurrent.atomic.AtomicInteger;
import java.util.concurrent.TimeUnit;
import java.util.concurrent.Executors;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.RejectedExecutionException;

import java.io.File;

import graph.State;
import graph.Graph;
import graph.GraphFactory;

import ndfs.NDFS;
import ndfs.Result;
import ndfs.CycleFound;
import ndfs.NoCycleFound;
import ndfs.MapWithDefaultValues;

public class NNDFS implements NDFS {

  private File file;
  private MapWithDefaultValues<State, Boolean> isRed;
  private MapWithDefaultValues<State, AtomicInteger> visitCount;
  private int nThreads;

  private static final int TIMEOUT = 50;

  public NNDFS(File file, int nThreads){
    this.file = file;
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

    ExecutorService executor = Executors.newFixedThreadPool(nThreads);
    
    try{
      for (int i = 0; i < nThreads; ++i){
        worker[i] = new Worker(file, isRed, visitCount, getRandomSeed(i), executor);
        try {
          executor.submit(worker[i]);
        } catch (RejectedExecutionException re) {
          // Do Nothing
        }
      }
    } catch (Exception e) {
      e.printStackTrace();

      // This should not be in finally block:
      // It does not work with 1 thread, because service is shutdown
      // and that poor thread is interrupted before he could finish the work
      // So he returns without finding cycle (in the case where he should have found one)
      System.out.println("Calling shutdown()...");
      executor.shutdownNow();
      try {
        executor.awaitTermination(TIMEOUT, TimeUnit.SECONDS);
      } catch (InterruptedException ie) {}
    }
    
  }

  public void ndfs() throws Result {
    nndfs(null);
  }
}
