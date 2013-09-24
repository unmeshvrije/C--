import java.util.ArrayList;
import java.util.List;

import graph.State;

public class NDFSState {
  
  private State state;
  private long uniqueIndex;
  private ArrayList<NDFSState> successors;
  
  // constructor
  public NDFSState(
      State state,
      long uniqueIndex
  ){
    this.uniqueIndex = uniqueIndex;
    this.state = state;
    this.successors = null; // can be assigned using setSuccessors()
  }
  
  public void setSuccessors(ArrayList<NDFSState> successors){
    this.successors = successors;  
  }
  
  
  public long getUniqueIndex(){
    return this.uniqueIndex;
  }
  
  public List<NDFSState> post(){ 
    return successors;
  }
  
  // package access !!!
  State getState(){
    return state;
  }
}
