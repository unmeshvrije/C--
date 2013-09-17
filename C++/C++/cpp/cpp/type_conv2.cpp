

/**********************User defined type to  Built-in type *********************************/

/*Generally for "=" operator (Assignment operator),
L.H.S. must be of "user defined type"
& L.H.S. object calls function & R.H.S. is paramater

Here   b = y;  where b is built-in data type
		and y is obj of class year

	y (R.H.S.)calls the function ( "CASTING FUNCTION" )
*/

#include<iostream>
using namespace std;

class year
{
int yy;

public:
year(){yy=65;}


operator char()    //CASTING FUNCTION  NAME ITSELF  is a RETURN TYPE
{
  cout <<endl<< "In Casting Function...";
   return yy;
}


void display()
{
cout<<"\n\t\tyy="<< yy;
}
};

int main ()
{
int x;
char z;
year y1;// default constructor is  called
// y1.yy =10

 
/***************************************************/
x=y1;   //call to casting function

z = y1; // same casting function is used
/***************************************************/
cout<<x;

cout <<endl << z;

return 0;
}
