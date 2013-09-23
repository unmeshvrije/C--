import java.lang.OutOfMemoryError;

import java.util.HashSet;
import java.util.ArrayList;
import java.util.HashMap;

import graph.Graph;
import graph.State;


public class NDFSGraph {
  
  Graph graph;
  long maxExploredNodes
  
  // use maxExploredNodes = 0 to explore the whole graph
  // WARNING: this could cause an out of memory error
  public NDFSGraph(Graph graph,long maxExploredNodes){
		this.graph = graph;
		this.maxExploredNodes = maxExploredNodes;
	}
  
  public State getInitialState(){
		return graph.getInitialState();
	}
  
  
  // do we want a member to cache it?
  // public ArrayList<NDFSState> allStates;
  
  
  // We decided to use an array instead of ArrayList
  public NDFSState[] getAllStates() 
			throws OutOfMemoryError
	{
		HashSet<State> stateSet = new HashSet<State>();
		HashSet<NDFSState> NDFSStateSet = new HashSet<NDFSState>();
		stateSet.add(getInitialState());
		
		boolean setChanged;
		
		// explore the graph and put the nodes in stateSet 
		do{
			setChanged = false;
			for(State s : stateSet){
				setChanged |= stateSet.addAll(graph.post(s));
			}			
		}while( false
				|| setChanged 
				|| ((maxEploredNodes != 0) && (stateSet.size() > maxExploredNodes))
		);
		
		
		// this number will be the uniqueIndex of every NDFSState
		int index = 0;
		
		// use a temporary hashMap for fast lookup on uniqueIndex'es
		// will be used below to assign successors
		HashMap<State,Integer> table = new HashMap<State,Integer>();
		
		// hand out uniqueIndexes, put every state in the hashMap 
		for(State s : stateSet){
			NDFSStateSet.add(new NDFSState(s,index));
			table.put(s,new Integer(index));
			index++;
		}
		
		// assign successors: 
		
		// for each node in the graph
		for(NDFSState ns : NDFSStateSet){
			
			// create a new arrayList to temporarily store its successors
			ArrayList<NDFSState> nsSucc = new ArrayList<NDFSState>();
			
			// look up all successors in hashmap
			for(State succ : graph.post(ns.getState())){
				nsSucc.add(new NDFSState(succ,table.get(succ)));
			} 
			
			// assign successors set.
			ns.setSuccessors(nsSucc);
		}
		
		
		return (NDFSState[]) NDFSStateSet.toArray();
	}
	
  public ArrayList<NDFSState> permuteSuccessors(NDFSState state){
		return null;
	}
}
