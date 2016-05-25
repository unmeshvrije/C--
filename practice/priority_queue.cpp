#include<iostream>
#include<queue>
#include<vector>

using namespace std;

template <typename T> void print_queue(T &q){
  while (!q.empty()) {
    cout << q.top() << " ";
    q.pop();
  }
  cout << endl;
}

int main() {

  priority_queue<int> max_heap;
  priority_queue<int, std::vector<int>, std::greater<int> > min_heap;

  max_heap.push(4);
  max_heap.push(14);
  max_heap.push(45);
  max_heap.push(7);
  max_heap.push(85);
  max_heap.push(43);
  max_heap.push(23);

  min_heap.push(4);
  min_heap.push(14);
  min_heap.push(45);
  min_heap.push(7);
  min_heap.push(85);
  min_heap.push(43);
  min_heap.push(23);

  print_queue(max_heap);
  print_queue(min_heap);
  return 0;
}
