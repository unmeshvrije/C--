#include <iostream>

using namespace std;

void fun(unique_ptr& q) {
}

int main(void) {
    
    unique_ptr<int> ptr = make_unique<int>();
    *ptr = 10;

    cout << *ptr << endl;
    return 0;
}
