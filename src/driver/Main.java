package driver;



import java.io.File;
import java.io.FileNotFoundException;

import java.util.Map;
import java.util.HashMap;
import java.util.BitSet;

import graph.GraphFactory;
import graph.Graph;
import graph.State;

import ndfs.nndfs.Color;

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
    System.out.println("Usage: bin/ndfs <file> <version> <nrWorkers>");
    System.out.println("  where"); 
    System.out.println("  <file> is a Promela file (.prom)");
    System.out.println("  <version> is one of {seq,alg2,alg3,op1,op2,op3,op4}");
  }

  private static void runMCNDFS(File file, String version, BitSet optimizations) throws FileNotFoundException, ArgumentException {
    Graph graph = GraphFactory.createGraph(file);

    NDFS ndfs = null;
    if (version.equals("alg2")) {
      ndfs = NDFSFactory.createMCNDFSAlg2(graph);
    } else if (version.equals("alg3")) {
      ndfs = NDFSFactory.createMCNDFSAlg3(graph);
    } else if (version.equals("op")) {
     // ndfs = NDFSFactory.createMCNDFSOptimizations(graph, optimizations);
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


  private static void dispatch(File file, String version, int nrWorkers)
      throws ArgumentException, FileNotFoundException 
  {
    if (version.equals("seq")) {
      if (nrWorkers != 1) {
        throw new ArgumentException("seq can only run with 1 worker");
      }
      Map<State, Color> map = new HashMap<State, Color>();
      runNDFS(map, file);
    } else if ( false
              || version.equals("alg2")
              ||(version.equals("alg3"))
    ) {
      runMCNDFS(file, version, null);
    } else if (version.contains("op")) {
      BitSet bitset = new BitSet(4);
      for (int i = 2; i < version.length(); ++i) {
        bitset.set(version.charAt(i) - 1);
      }

      runMCNDFS(file, "op", bitset);
    }
    else {
      throw new ArgumentException("Unkown version: " + version);
    }
  }


  public static void main(String[] argv) {
    try {
      if (argv.length != 3) 
        throw new ArgumentException("Wrong number of arguments");
      File file = new File(argv[0]);
      String version = argv[1];
      int nrWorkers = new Integer(argv[2]);

      dispatch(file, version, nrWorkers);
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
