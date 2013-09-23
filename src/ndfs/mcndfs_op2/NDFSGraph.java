import java.lang.OutOfMemoryError;

import java.util.HashSet;
import java.util.ArrayList;
import java.util.HashMap;

import graph.Graph;
import graph.State;


public class NDFSGraph {
  
  Graph graph;
  
  public NDFSGraph(Graph graph){
		this.graph = graph;
	}
  
  public State getInitialState(){
		return graph.getInitialState();
	}
  
  
  // do we want a member to cache it?
  // public ArrayList<NDFSState> allStates;
  
  
  //
  //
  // WARNING: WE DO NOT LIMIT THE SEARCH YET TO A CONFIGURABLE AMOUNT OF NODES
  //
  // 
  
  
  // We decided to use an array instead of ArrayList
  public NDFSState[] getAllStates() 
			throws OutOfMemoryError
	{
		HashSet<State> stateSet = new HashSet<State>();
		HashSet<NDFSState> NDFSStateSet = new HashSet<NDFSState>();
		stateSet.add(getInitialState());
		
		boolean setChanged;
		
		// explore the whole graph and put all nodes in stateSet 
		do{
			setChanged = false;
			for(State s : stateSet){
				setChanged |= stateSet.addAll(graph.post(s));
			}			
		}while(setChanged);
		
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
