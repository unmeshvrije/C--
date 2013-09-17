#include<iostream>
using namespace std;
int m =10 ;	//global variable
main()
{
     	int m =20;
	{ //starting the block
		int k = m;
		int m = 30;
	  cout << endl << " m = " << m;
	  cout << endl << " k = " << k;
	  cout << endl << " ::m = " << ::m;
	}//ending the block
	cout << endl << " m = " << m;
	cout << endl << " ::m = " << ::m;
}
