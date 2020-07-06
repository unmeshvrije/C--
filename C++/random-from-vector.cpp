#include<iostream>
#include<vector>
using namespace std;

template<class BidiIter >
BidiIter random_unique(BidiIter begin, BidiIter end, size_t num_random) {
    size_t left = std::distance(begin, end);
    srand(time(0));
    while (num_random--) {
        BidiIter r = begin;
        std::advance(r, rand()%left);
        std::swap(*begin, *r);
        ++begin;
        --left;
    }
    return begin;
}

int main() {

    vector<int> test(10000); 
    for (int i = 0; i < 10000; ++i) {
        test[i] = i;
    }
    random_unique(test.begin(), test.end(), 16);

    cout << "******" << endl;
    for (int i = 0; i < 16; ++i) {
        cout << test[i] << endl;
    }
}
