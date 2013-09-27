package ndfs.mcndfs_op2;

import java.util.ArrayList;
import java.util.List;

import graph.State;

public class NDFSState {
  
  private State state;
  private long uniqueIndex;
  private ArrayList<NDFSState> successors;
  
  // constructor: package access
  NDFSState(
      State state,
      long uniqueIndex
  ){
    this.uniqueIndex = uniqueIndex;
    this.state = state;
    this.successors = null; // can be assigned using setSuccessors()
  }
  
  // package access !!!
  void setSuccessors(ArrayList<NDFSState> successors){
    System.out.println(" this is ndfs state:: set sucessors()\n");
    this.successors = successors;  
  }
  
  
  public long getUniqueIndex(){
    return this.uniqueIndex;
  }
  
  public List<NDFSState> post(String str){ 
    System.out.printf(str + "this is ndfsstate::post(), my size is %d\n",successors.size());
    return successors;
  }
  
  public boolean isAccepting() {
    return state.isAccepting();
  }
  
  // package access !!!
  State getState(){
    return state;
  }
}
