#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    vector<pair<int, string>> names;
    names.push_back(make_pair(5,"dan"));
    names.push_back(make_pair(15,"ben"));
    names.push_back(make_pair(56,"rijk"));
    names.push_back(make_pair(3,"hema"));
    names.push_back(make_pair(24,"dirk"));

    for (auto p : names) {
        cout << p.first << " : " << p.second << endl;
    }

    cout << "****" << endl;

    std::sort(names.begin(), names.end(), [] (const pair<int, string> &a, const pair<int, string>& b)-> bool {
        return a.first < b.first;
    });

    for (auto p : names) {
        cout << p.first << " : " << p.second << endl;
    }

    return 0;
}
