package ndfs;

import java.util.Map;
import java.util.BitSet;

import graph.Graph;
import graph.State;


public class NDFSFactory {

  public static NDFS createNNDFS(Graph graph, 
    Map<State, ndfs.Color> map) {
    return new ndfs.nndfs.NNDFS(graph, map);
  }

  public static NDFS createMCNDFSAlg2(Graph graph, int nWorkers) {
    return new ndfs.mcndfs_alg2.NNDFS(graph, nWorkers);
  }
  
  public static NDFS createMCNDFSAlg3(Graph graph, int nWorkers){
    return new ndfs.mcndfs_alg3.NNDFS(graph, nWorkers);
  }

  public static NDFS createMCNDFSOp1(Graph graph, int nWorkers, int depth) {
    return new ndfs.mcndfs_op1.Master(graph, nWorkers, depth);
  }

}
