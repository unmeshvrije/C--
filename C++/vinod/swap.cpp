#include<iostream> 

using namespace std;

void swap(int &a, int & b) {
    int t = a;
    a = b;
    b = t;
}

int main(void) {

    int x = 5, y =6;
    cout << x << " , " << y << endl;
    swap(x,y);
    cout << x << " , " << y << endl;
}
