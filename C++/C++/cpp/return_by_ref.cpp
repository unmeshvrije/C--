#include<iostream>
using namespace std;
int& max(int &x ,int &y) //returns reference
{
	if(x > y)  return x;
	  return y;
}
main()
{  	int a=4,b=7;
	cout << "a= "<<a <<" b = " <<b;
	max(a,b) = -1;  cout << endl;
	cout << "a= "<<a <<" b = " <<b;
}
/*
Since return type of max is int&,
the function returns reference to x or y
(not the values). So function call-max(a,b)
will result into reference to a or reference
to b depending on their values.Hence, this
function call can appear on LHS of assignment
statement.
i.e. max(a,b) = -1 ;
is legal and 
it assigns -1 to a if a is larger
otherwise assigns -1 to b.
*/
