#include<iostream>
using namespace std;

main()
{
   int Total=235,n=23;
   float avg;
   
   
   
   avg = Total/float(n); //allowed
  //avg = Total/(float)n;   // allowed
   //avg = (float) (Total/n);// not float answer
   //avg = (float)Total / n;
   
   cout<< avg;
}
