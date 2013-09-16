package ndfs.mcndfs_alg2;

import java.lang.Runnable;
import java.util.HashMap;

import graph.Graph;
import graph.State;

import ndfs.Result;
import ndfs.CycleFound;
import ndfs.NoCycleFound;
import ndfs.mcndfs_alg2.Color;

class Worker implements Runnable
{
    // TODO: decide scope
    private final Graph graph;
    private State state;
    private Colors colors;

    public Worker(final Graph graph)
    {
    	this.graph = graph;
        this.state = graph.getInitialState();
	this.colors = new Colors(new HashMap<State,Color>());
    }

    private void dfsRed(State s) throws Result {
        for (State t : graph.post(s)) {
            if (colors.hasColor(t, Color.CYAN)) {
                throw new CycleFound();
            }
            else if (colors.hasColor(t, Color.BLUE)) {
                colors.color(t, Color.RED);
                dfsRed(t);
            }
        }
    }


    private void dfsBlue(State s) throws Result {
        colors.color(s, Color.CYAN);
        for (State t : graph.post(s)) {
            if (colors.hasColor(t, Color.WHITE)) {
                dfsBlue(t);
            }
        }
        if (s.isAccepting()) {
            dfsRed(s);
            colors.color(s, Color.RED);
        }
        else {
            colors.color(s, Color.BLUE);
        }
    }

    public void run()
    {
        try {
	    dfsBlue(state);
	    throw new NoCycleFound();
	} catch (Result e) {
	    // TODO: Set a flag
	    System.out.println("We got : " + e.toString());
	}
    }

}
