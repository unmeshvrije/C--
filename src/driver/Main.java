package driver;



import java.io.File;
import java.io.FileNotFoundException;

import java.util.Map;
import java.util.HashMap;
import java.util.BitSet;

import graph.GraphFactory;
import graph.Graph;
import graph.State;

import ndfs.Color;

import ndfs.NDFS;
import ndfs.NDFSFactory;
import ndfs.Result;



public class Main {

  private static class ArgumentException extends Exception {
    private static final long serialVersionUID = 1L;
    ArgumentException(String message) {
      super(message);
    }
  };


  private static void printUsage() {
    System.out.println("Usage: bin/ndfs <file> <version> <nWorkers>");
    System.out.println("  where"); 
    System.out.println("  <file> is a Promela file (.prom)");
    System.out.println("  <version> is one of {seq,alg2,alg3,op1,op2,op3,op4}");
  }

  private static void runMCNDFS(File file, String version, int nWorkers, int depth) throws FileNotFoundException, ArgumentException {
    NDFS ndfs = null;
    
    if (version.equals("alg2")) {
      ndfs = NDFSFactory.createMCNDFSAlg2(file, nWorkers);
    } else if (version.equals("alg3")) {
      ndfs = NDFSFactory.createMCNDFSAlg3(file, nWorkers);
    } else if (version.equals("op1")) {
      ndfs = NDFSFactory.createMCNDFSOp1(file, nWorkers, depth);
    } else if (version.equals("op4")) {
      ndfs = NDFSFactory.createMCNDFSOp4(file, nWorkers);
    } else {
      throw new ArgumentException("Invalid arguments");
    }

    long start = System.currentTimeMillis();
    long end;

    try {
      ndfs.ndfs();
      //throw new Error("No result returned by naive");
    }
    catch (Result r) {
      end = System.currentTimeMillis();
      System.out.println(r.getMessage());
      System.out.printf("%s took %d ms\n", "MC_NDFS", end - start);
    }
  }

  private static void runNDFS(
        Map<State, Color> colorStore,
        File file
  ) throws FileNotFoundException 
  {
    Graph graph = GraphFactory.createGraph(file);
    NDFS ndfs = NDFSFactory.createNNDFS(graph, colorStore);
    long start = System.currentTimeMillis();
    long end;
  
    try {
      ndfs.ndfs();
      throw new Error("No result returned by seq");
    }
    catch (Result r) {
      end = System.currentTimeMillis();
      System.out.println(r.getMessage());
      System.out.printf("%s took %d ms\n", "SEQ_NDFC", end - start);
    }
  }


  private static void dispatch(File file, String version, int nWorkers, int depth)
      throws ArgumentException, FileNotFoundException 
  {
    if (version.equals("seq")) {
      if (nWorkers != 1) {
        throw new ArgumentException("seq can only run with 1 worker");
      }
      Map<State, Color> map = new HashMap<State, Color>();
      runNDFS(map, file);
    } else if ( false
              || version.equals("alg2")
              || version.equals("alg3")
              || version.equals("op1")
              || version.equals("op2")
              || version.equals("op3")
              || version.equals("op4")
    ){
      runMCNDFS(file, version, nWorkers, depth);
    } else {
      throw new ArgumentException("Unkown version: " + version);
    }
  }


  public static void main(String[] argv) {
    try {
    
      if (argv.length != 3 && argv.length != 4) 
        throw new ArgumentException("Wrong number of arguments");
        
      File file = new File(argv[0]);
      String version = argv[1];
      int nWorkers = new Integer(argv[2]);
      int depth = 0;
      
      if (argv.length > 3) {
        depth = new Integer(argv[3]);
      }

      dispatch(file, version, nWorkers, depth);
    }
    catch (FileNotFoundException e) {
      System.err.println(e.getMessage());
    }
    catch (ArgumentException e) {
      System.err.println(e.getMessage());
      printUsage();
    }
    catch (NumberFormatException e) {
      System.err.println(e.getMessage());
      printUsage();
    }
  }
}
