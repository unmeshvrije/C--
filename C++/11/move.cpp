#include <iostream>
#include <vector> //std::vector
#include <algorithm> //std::for_each

using namespace std;

void myfunc(int i) {
  cout << ' ' << i;
}

void* operator new (size_t size) {
    cout << "Allocating " << size << " bytes" << endl;
    return malloc(size);
}

class Vec {
  private:
  pair<vector<int>, int> my_vec;

  public:
  Vec(vector<int> v , int index) {
    my_vec.first = v;
    my_vec.second = index;
  }

  friend ostream& operator << (ostream& out, Vec &v) {
    for_each (v.my_vec.first.begin(), v.my_vec.first.end(), myfunc);
    out << endl << v.my_vec.second << endl;
    return out;
  }

  void print() {
    cout << "Hello" << endl;
  }
};

int main(){

  Vec x = Vec({1,2,3,4},2);
  cout << x;
  cout << "Address of x " << hex << &x << endl;
 // Vec y = x;
  //cout << y;

  Vec z = move(x);
  cout << "Now..." << endl;
  cout << z;
  cout << "Address of x " << hex << &x << endl;
  cout << "Address of z " << hex << &z << endl;
  //cout << x;
  x.print();
  return 0;
}
