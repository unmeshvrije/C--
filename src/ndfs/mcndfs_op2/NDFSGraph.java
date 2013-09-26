package ndfs.mcndfs_op2;

import java.lang.OutOfMemoryError;

import java.util.HashSet;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Random;
import java.util.Collections;

import graph.Graph;
import graph.State;


public class NDFSGraph {
  
  private Graph graph;
  private long maxExploredNodes;
  private ArrayList<NDFSState> allStates;
  
  private NDFSState initialState;
  
  // use maxExploredNodes = 0 to explore the whole graph
  // WARNING: this could cause an out of memory error
  public NDFSGraph(Graph graph,long maxExploredNodes){
    this.graph = graph;
    this.maxExploredNodes = maxExploredNodes;
    this.allStates = null;
    this.initialState = null;
  }
  
  public NDFSState getInitialState(){
    return initialState;
  }
  
  
  
  
  // We decided to use an array instead of ArrayList
  public ArrayList<NDFSState> getAllStates() 
      throws OutOfMemoryError
  {
    if(allStates != null){
      return allStates;
    }
    
    // we use two hashsets, because we cannot modify one using addAll when iterating over it
    HashSet<State> stateSet = new HashSet<State>();
    HashSet<State> stateSet2 = null;
    
    stateSet.add(graph.getInitialState());
    
    // explore the graph and put the nodes in stateSet 
    do{
      stateSet2 = stateSet;
      stateSet = new HashSet<State>();
      for(State s : stateSet2){
        stateSet.addAll(graph.post(s));
        stateSet.add(s);
      }      
    }while( false
        || stateSet.size() > stateSet2.size() 
        || ((maxExploredNodes != 0) && (stateSet.size() > maxExploredNodes))
    );
    
    
    
    
    
    // this number will be the uniqueIndex of every NDFSState
    long index = 0;
    
    // use a temporary hashMap for fast lookup on uniqueIndex'es
    // will be used below to assign successors
    HashMap<State,Long> table = new HashMap<State,Long>();
   
    HashSet<NDFSState> NDFSStateSet = new HashSet<NDFSState>();
  
    
    // hand out uniqueIndexes, put every state in the hashMap 
    for(State s : stateSet){
      
      NDFSState ns = new NDFSState(s,index);  
      
      // this work around is is only used because we want to 
      // be able to return an NDFSState at getInitialState()
      if(s.hashCode() == graph.getInitialState().hashCode()){
        this.initialState = ns;
      }
      
      NDFSStateSet.add(ns);
      table.put(s,new Long(index));
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
    
    
    allStates = new ArrayList<NDFSState>(NDFSStateSet);
	  return allStates; 
  }
  
  public void permuteSuccessors(long l){
    
    if(allStates == null){
      System.out.println("Called NDFSGraph.permuteSuccessors with allStates == null\n");
      System.exit(1);
    }
    
    Random random = new Random(l);
    for(int i=0;i<allStates.size();i++){
      Collections.shuffle(allStates.get(i).post(), random);
    }
  }
  
  
}
