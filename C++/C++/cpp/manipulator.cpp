// Manipulators are operators that are used 
// to format the display of data.
//Most commonly used manipulators are :
// 'endl' and 'setw'


#include<iostream>
#include<iomanip>  	//for setw
using namespace std;

int main()
{
	int x=10,y=2000;
	
	cout << setw(10) << "X = " <<setw(10) <<x <<endl
	<< setw(20) << "Y = " << y;
  return 0;
}

