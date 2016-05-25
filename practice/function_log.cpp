#include<iostream>
#include<vector>
#include<stack>
#include<map>
#include<iomanip>
#include<cassert>

using namespace std;

struct FunctionLog
{
  string name;
  bool entry; //If it is entry or exit
  int timestamp;
  FunctionLog(string s, bool e, int ts):name(s),entry(e),timestamp(ts){}
};

void print_log(vector<FunctionLog*> &log)
{
  for (int i = 0; i < log.size(); ++i) {
    cout << i << ") " << log[i]->name << " : " << setw(5) << (log[i]->entry ? "entry" : "exit") << " : " << log[i]->timestamp << endl;
  }
}

void find_cpu_burst(vector<FunctionLog*> &log) {

  int size = log.size();
  assert(size > 1);

  std::map<string, int> cpu_bursts;
  stack<string> fun_stack;

  int previous_timestamp = log[0]->timestamp;
  if (!log[0]->entry) {
    cerr << "Log cannot start with exit function log." << endl;
    return;
  }

  fun_stack.push(log[0]->name);
  for (int i = 1; i < size; ++i) {
    if (log[i]->timestamp < previous_timestamp) {
      cerr << "Timestamps must be incrementing." << endl;
      return;
    } else {
      previous_timestamp = log[i]->timestamp;
    }

    string top = fun_stack.top();

    if (log[i]->entry) {
      fun_stack.push(log[i]->name);
    } else {

      // Remove from stack only if the name matches
      if(log[i]->name.compare(top) == 0) {
        fun_stack.pop();
      }
    }
    
    if (log[i-1]->entry) {
      // Previous was entry log
      cpu_bursts[log[i-1]->name] += log[i]->timestamp - log[i-1]->timestamp;
    } else {
      // Previous was exit log
      cpu_bursts[top] += log[i]->timestamp - log[i-1]->timestamp;
    }
  }

  assert(fun_stack.empty());

  for (map<string,int>::const_iterator it = cpu_bursts.begin(); it != cpu_bursts.end(); ++it) {
    cout << it->first << " : " << it->second << endl;
  }
}

int main(void){

  vector<FunctionLog*> log;

  /*
  log.push_back(new FunctionLog("foo", true, 100));
  log.push_back(new FunctionLog("bar", true, 110));
  log.push_back(new FunctionLog("bar", false, 120));
  log.push_back(new FunctionLog("foo", false, 130));
  */

  /*
  log.push_back(new FunctionLog("foo", true, 100));
  log.push_back(new FunctionLog("bar", true, 110));
  log.push_back(new FunctionLog("baz", true, 120));
  log.push_back(new FunctionLog("baz", false, 140));
  log.push_back(new FunctionLog("bar", false, 180));
  log.push_back(new FunctionLog("foo", false, 200));
  */

  /*
  log.push_back(new FunctionLog("foo", true, 100));
  log.push_back(new FunctionLog("bar", true, 110));
  log.push_back(new FunctionLog("baz", true, 120));
  log.push_back(new FunctionLog("baz", false, 140));
  log.push_back(new FunctionLog("bar", false, 180));
  log.push_back(new FunctionLog("raz", true, 220));
  log.push_back(new FunctionLog("raz", false, 240));
  log.push_back(new FunctionLog("foo", false, 300));
  */

  /*
  log.push_back(new FunctionLog("foo", true, 100));
  log.push_back(new FunctionLog("foo", true, 120));
  log.push_back(new FunctionLog("foo", true, 130));
  log.push_back(new FunctionLog("foo", false, 140));
  log.push_back(new FunctionLog("foo", false, 150));
  log.push_back(new FunctionLog("foo", false, 160));
  */

  log.push_back(new FunctionLog("foo", true, 100));
  log.push_back(new FunctionLog("bar", true, 120));
  log.push_back(new FunctionLog("foo", true, 140));
  log.push_back(new FunctionLog("foo", false, 170));
  log.push_back(new FunctionLog("bar", false, 190));
  log.push_back(new FunctionLog("foo", false, 220));

  print_log(log);
  cout << endl;
  find_cpu_burst(log);
  return 0;
}
