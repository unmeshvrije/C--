#include <iostream>

using namespace std;

int main(void) {
    string a = "annvar";
    cout << a << endl;
    a = a.substr(a.find("ann")+3);
    cout << a << endl;
}
