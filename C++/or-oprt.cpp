#include <iostream>
int main(void) {
    int x = 4;
    std::cout << "X = " << x << std::endl;
    x |= 2; // x = x | 2
    std::cout << "Now, X = " << x << std::endl;
    return 0;
}
