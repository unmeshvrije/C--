#include<iostream>

using namespace std;

int main(void) {

    stringstream ss;
    ss << 1;
    string test = ss.str();

    cout << test << endl;
    return 0;
}
