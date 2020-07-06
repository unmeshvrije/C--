#include<vector>
#include <iostream>
using namespace std;

int main() {
    vector<int> x;
    x.push_back(1);
    x.push_back(2);
    x.push_back(3);
    x.push_back(5);
    for (auto n : x) {
        cout << n <<endl;
    }

    vector<int>y = x;

    x.clear();

    for (auto item: y) {
        cout << item << endl;
    }
   // vector<int>().swap(x);
   // cout << "before" << endl;
   // for (auto n : x) {
   //     cout << n <<endl;
   // }
   // cout << "after" << endl;
    return 0;
}
