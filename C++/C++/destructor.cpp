#include <iostream>

using namespace std;

class Test {

    int *ptr;

    public:
    Test() {
        ptr = new int(10);
        cout << "CTOR" << endl;
    }

    ~Test() {
        delete ptr;
        cout << "DTOR" << endl;
    }
};

int main(void) {
    Test t;
    return 0;
}
