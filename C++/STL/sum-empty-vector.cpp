#include<iostream>
#include<vector>
#include<numeric>
#include<vector>
using namespace std;
int main(void) {
    vector<uint64_t> temp;

    uint64_t a =std::accumulate(temp.begin(), temp.end(), 0.0) / temp.size();
    cout  << a << endl;
    return 0;
}
