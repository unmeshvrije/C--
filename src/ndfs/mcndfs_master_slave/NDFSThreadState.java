package ndfs.mcndfs_master_slave;

public enum NDFSThreadState {
  DONE,       // finished task, no cycle found
  CYCLE_FOUND,// found a cycle
  BUSY        // still computing
}
