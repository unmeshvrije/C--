package ndfs;

import java.util.Map;
import java.util.BitSet;

import graph.Graph;
import graph.State;


public class NDFSFactory {

  public static NDFS createNNDFS(Graph graph, 
    Map<State, ndfs.nndfs.Color> map) {
    return new ndfs.nndfs.NNDFS(graph, map);
  }

  public static NDFS createMCNDFSAlg2(Graph graph) {
    return new ndfs.mcndfs_alg2.NNDFS(graph);
  }
  
  public static NDFS createMCNDFSAlg3(Graph graph){
    return new ndfs.mcndfs_alg3.NNDFS(graph);
  }

 /* public static NDFS createMCNDFSOptimizations(Graph graph, BitSet optimizations) {
    return new ndfs.mcndfs_optimizations.NNDFS(graph, optimizations);
  }*/

}
