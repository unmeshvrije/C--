#include<iostream>
#include<sstream>
#include<string.h>
using namespace std;

int main()
{
	int x;
	char *c,*ch,*d;
	strcpy(c,"asdf");
	
	cout<<"\nc = " <<c;

x= (int)random();
cout<<"\nx ="<<x;

d=initstate((long int)65,c,20);
cout<<"\nd="<< d <<"stopped";

ch=(ch,setstate("asdf"));

cout<<"\nch="<<ch;

return 0;
}
