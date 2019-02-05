#include<iostream>
using namespace std;

int main(void) {
    uint64_t i = -17;
    cout << __builtin_popcount(i) << endl;;
    return 0;
}
