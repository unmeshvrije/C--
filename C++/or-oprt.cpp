#include <iostream>
using namespace std;
int main(void) {
    int x = 4;
    std::cout << "X = " << x << std::endl;
    x |= 2; // x = x | 2
    std::cout << "Now, X = " << x << std::endl;

    double a = 6.234;
    double b = 45.123554;
    double c = (double) ((uint64_t)a | (uint64_t)b);
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "a|b = " << c << endl;
    return 0;
}
