#include<iostream>
#include <string>
#include<unordered_map>
using namespace std;

int main(void) {
    unordered_map<char, int> oc;
    string s = "Hello";

    for (int i = 0; i < s.length(); ++i) {
        oc[s[i]]++;
    }

    for (auto iter = oc.begin(); iter != oc.end(); iter++) {
        cout << iter->first << " , " << iter->second << endl;
    }

    int N = s.length();
    int r[N][N];

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << i+j << "\t";
        }
        cout << endl;
    }
    return 0;
}
