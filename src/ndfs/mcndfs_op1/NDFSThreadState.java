package ndfs.mcndfs_op1;

public enum NDFSThreadState {
  DONE,       // finished task, no cycle found
  CYCLE_FOUND,// found a cycle
  BUSY        // still computing
}
