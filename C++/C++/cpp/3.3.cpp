#include<iostream>
using namespace std;

main()
{
  int i=5;
  while(i)
  {
     switch(i)
     {
        default:
	case 4:
	case 5:
	cout << i << endl;
	break;
	
	case 1: continue;
	case 2:
	case 3:
	cout << i << endl;
	break;
     }
     i--;
  }
}
