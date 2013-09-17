#include<iostream>
using namespace std;

double SI(double p, double r =5.6 , int n=5)
{
  cout<<endl << "p =" << p;
  cout<<endl << "r =" << r;
  cout<<endl << "n =" << n;
  
  return (p*r*n)/100;
}

main()
{
   double pple=1000,rate=4.5;
   int years=10;
   cout <<endl << "SI = " 
   <<SI( pple,rate);
   cout <<endl << "SI = " 
   << SI( pple,rate,years);
   
   SI(1000);
   
   
}
