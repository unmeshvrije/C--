#include<iostream>
#include <string>
#include<unordered_map>
using namespace std;

int main(void) {
    unordered_map<char, int> oc;
    string s = "Hello";
    typedef unordered_map<char,int>::value_type map_value_type;
    for (int i = 0; i < s.length(); ++i) {
        oc[s[i]]++;
    }

    for (auto iter = oc.begin(); iter != oc.end(); iter++) {
        cout << iter->first << " , " << iter->second << endl;
    }

int value = 1;
if (oc.end() != find_if(oc.begin(),oc.end(),[&value](const map_value_type& vt)
                                                 { return vt.second == value; }))
   std::cout << "Value found." << std::endl;
else
   std::cout << "Value NOT found." << std::endl;
    return 0;
}
