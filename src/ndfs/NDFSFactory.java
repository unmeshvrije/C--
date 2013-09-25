package ndfs;

import java.util.Map;
import java.util.BitSet;

import java.io.File;

import graph.Graph;
import graph.State;


public class NDFSFactory {

  public static NDFS createNNDFS(Graph graph, 
    Map<State, ndfs.Color> map) {
    return new ndfs.nndfs.NNDFS(graph, map);
  }

  public static NDFS createMCNDFSAlg2(File file, int nWorkers) {
    return new ndfs.mcndfs_alg2.NNDFS(file, nWorkers);
  }
  
  public static NDFS createMCNDFSAlg3(File file, int nWorkers){
    return new ndfs.mcndfs_alg3.NNDFS(file, nWorkers);
  }

  public static NDFS createMCNDFSOp1(File file, int nWorkers, int depth) {
    return new ndfs.mcndfs_op1.NNDFS(file, nWorkers);
  }

  /*public static NDFS createMCNDFSOp2(File file, int nWorkers) {
    return new ndfs.mcndfs_op2.NNDFS(file, nWorkers);
  }*/

  /*public static NDFS createMCNDFSOp3(File file, int nWorkers) {
    return new ndfs.mcndfs_op3.NNDFS(file, nWorkers);
  }*/

  public static NDFS createMCNDFSOp4(File file, int nWorkers) {
    return new ndfs.mcndfs_op4.NNDFS(file, nWorkers);
  }

}
