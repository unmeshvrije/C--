package ndfs.mcndfs_alg2;



import java.util.Map;

import graph.State;
import graph.Graph;

import ndfs.NDFS;
import ndfs.Result;
import ndfs.CycleFound;
import ndfs.NoCycleFound;



public class NNDFS implements NDFS {

    private Graph graph;

    public NNDFS(Graph graph) {
        this.graph = graph;
    }

    public void init() {}

    private void nndfs(State s) throws Result {
    	// Create threads here
        // Thread run() method will call dfsBlue(s);
        //throw new NoCycleFound();
	int n = 2;
	Worker[] worker = new Worker[n];

	try {
		for (int i = 0; i < n; ++i) {
		    worker[i] = new Worker(graph);
		    worker[i].run();
		}
	} catch (Exception e) {
	    //e.printStackTrace();
	    System.out.println("Our Exception");
	}
    }


    public void ndfs() throws Result {
        nndfs(graph.getInitialState());
    }
}
