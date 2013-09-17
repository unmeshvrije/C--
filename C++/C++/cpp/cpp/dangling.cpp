#include<iostream>
using namespace std;

main()
{
int *p= new int;
int* q;

q=p;

*p=3;
cout<<"\n*q="<<*q; // will print 3

*q=5;
cout<<"\n*p="<<*p; // will print 5

delete p;
cout<<"\n*p="<<*p;
cout <<"\n*q="<<*q; //after deleting p ,q will become dangling pointer & deleted area is
		   //dangling reference
}
