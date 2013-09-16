package ndfs.mcndfs_alg2;

import java.lang.Runnable;
import java.util.HashMap;

import graph.Graph;
import graph.State;

import ndfs.Result;
import ndfs.CycleFound;
import ndfs.NoCycleFound;
import ndfs.mcndfs_alg2.MapWithDefaultValues;

class Worker implements Runnable
{
    // TODO: decide scope
    private final Graph graph;
    private State state;
    private MapWithDefaultValues<State,Color> colors;

    public Worker(final Graph graph)
    {
        this.graph = graph;
        this.state = graph.getInitialState();
        this.colors = new MapWithDefaultValues<State,Color>(new HashMap<State,Color>(),Color.WHITE);
    }

    private void dfsRed(State s) throws Result {
        for (State t : graph.post(s)) {
            if (colors.hasKeyValuePair(t, Color.CYAN)) {
                throw new CycleFound();
            }
            else if (colors.hasKeyValuePair(t, Color.BLUE)) {
                colors.setValue(t,Color.RED); // TODO complicated stuff here!!!
                dfsRed(t);
            }
        }
    }


    private void dfsBlue(State s) throws Result {
        colors.setValue(s, Color.CYAN);
        for (State t : graph.post(s)) {
            if (colors.hasKeyValuePair(t, Color.WHITE)) {
                dfsBlue(t);
            }
        }
        if (s.isAccepting()) {
            dfsRed(s);
            colors.setValue(s, Color.RED);
        }
        else {
            colors.setValue(s, Color.BLUE);
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
