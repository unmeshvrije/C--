#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>

using namespace std;


void topological_sort(unordered_map<int, <unordered_set<int> >& graph, 
    unordered_map<int, bool>& state,
    int vertex,
    vector<int>& order) {

  if (state[vertex] == false) {
    return;
  }

  state[vertex] = true;
  unordered_set<int>::const_iterator it;
  for (it = graph[vertex].begin(); it != graph[vertex].end(); ++it) {
    topological_sort(graph, state, *it, order);
  }
  state[vertex] = false;
  order.push_front(vertex);
}

int main(void) {
  unordered_map<int, <unordered_set<int> > graph;//(n, unsorted_set<int>());
  graph[0].insert(1);
  graph[0].insert(2);
  graph[1].insert(2);
  graph[2].insert(3);
  graph[3].insert(4);
  graph[3].insert(5);
  graph[4].insert(5);
 // graph[5] = unordered_set<int>();

  int n = graph.size();
  unordered_map<int, bool>state;
  unordered_map<int, unordered_set<int> >::const_iterator it;
  for (it = graph.begin(); it != graph.end(); ++it) {
    state[it->first] = false;
  }

  vector<int> order;
  topological_sort(graph, state, 0, order);

  for (int i = 0; i < order.size(); ++i) {
    cout << order[i] << " ";
  }
  cout << endl;

  return 0;
}
