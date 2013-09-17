#include<iostream>
using namespace std;


main()
{
  enum Color{Red,Yellow,Green};
  enum days{mon = 2,tue,wed, thu = 6, fri, sat, sun};
  
//  cout << Red << Yellow <<Green ;
  
  cout << "mon =" << mon << endl;
  cout << "tue =" << tue << endl;
  cout << "wed =" << wed << endl;
  cout << "thu =" << thu << endl;
  cout << "fri =" << fri << endl;
  cout << "sat =" << sat << endl;
  cout << "sun =" << sun << endl;
 
}
