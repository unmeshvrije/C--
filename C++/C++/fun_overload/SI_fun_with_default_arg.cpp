#include <iostream>
using namespace std;

float SI(float p,float n = 2,float r = 5)
{
   return (p * r * n) / 100;
}


int main(void)
{
   float pple, rate, n;
   cout << "Enter pple:";
   cin >> pple;

   cout << endl << "Enter rate:";
   cin >> rate;
   cout << endl << "Enter No of Years:";
   cin >> n;


cout << endl <<"SI = "<< SI(pple);
cout << endl <<"SI = "<< SI(pple, n);
cout << endl <<"SI = "<< SI(pple, n, rate);
   return 0;
}
