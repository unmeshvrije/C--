package ndfs;

import java.util.Map;

import graph.Graph;
import graph.State;


public class NDFSFactory {

  public static NDFS createNNDFS(Graph graph, 
    Map<State, ndfs.nndfs.Color> map) {
    return new ndfs.nndfs.NNDFS(graph, map);
  }

  public static NDFS createMCNDFSNaive(Graph graph) {
    return new ndfs.mcndfs_alg2.NNDFS(graph);
  }
  
  public static NDFS createMCNDFSAllRedEarlyCycle(Graph graph){
    return new ndfs.mcndfs_alg3.NNDFS(graph);
  }

}
