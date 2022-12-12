#include <iostream>

using namespace std;

int main(void) {
    auto func = [] (){ cout << "hello" << endl; };
    func();
}
