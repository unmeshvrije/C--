package ndfs.mcndfs_op2;

import java.util.HashMap;
import java.util.BitSet;
import java.util.concurrent.Future;
import java.util.concurrent.atomic.AtomicInteger;
import java.util.concurrent.Executors;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.RejectedExecutionException;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.TimeoutException;
import java.io.File;

import java.util.concurrent.TimeUnit;

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
  //private MapWithDefaultValues<State, Boolean> isRed;
  private BitSet isRed;  
  private MapWithDefaultValues<NDFSState, AtomicInteger> visitCount;
  private int nThreads;
  
  public NNDFS(File file, int nThreads){
    this.file = file;
//    this.isRed = new MapWithDefaultValues<State, Boolean>(new HashMap<State, Boolean>(), false);
    this.isRed = new BitSet();

    this.visitCount = new MapWithDefaultValues<NDFSState, AtomicInteger>(new HashMap<NDFSState, AtomicInteger>(), new AtomicInteger(0));
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
    Future[] future = new Future[nThreads];
    
    ExecutorService executor = Executors.newFixedThreadPool(nThreads);

    try{
      for (int i = 0; i < nThreads; ++i){
        worker[i] = new Worker(file, isRed, visitCount, getRandomSeed(i), executor);
        try{
          future[i] = executor.submit(worker[i]);
        } catch (RejectedExecutionException re) {
          // Do Nothing
        }
        
      }
    } catch (Exception e) {
      e.printStackTrace();
      executor.shutdownNow();
    } finally{
        /*try {
          for (int i = 0; i < nThreads; ++i){
            future[i].get(5000, TimeUnit.MILLISECONDS);
          }
        } catch (InterruptedException ie){}
          catch (ExecutionException ee){}
          catch (TimeoutException ee){}
          System.out.println("shutting down");
      }*/
    }
  }

  public void ndfs() throws Result {
    nndfs(null);
  }
}
