#include <iostream>
using namespace std;


int main()
{
    int i = 5;
    int *ptr = &i;
    
    long j = reinterpret_cast<long>(ptr);
//    long j = (long)(ptr);
    cout << "j = 0x" << hex << j << endl;
    cout << "ptr = " << ptr << endl;
    *((int*)j) = 11;
    cout << "i = " << dec << i << endl;
}
