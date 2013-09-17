#include<iostream>
#include<math.h>
using namespace std;

int main()
{
int x=10;
cout.fill('*');
cout.width(12);
cout<<x;
cout <<endl;

cout.width(5);  //here previous "fill" effect is preserved but "width" effect is limited for 
		//one upcoming output only
cout<< ++x;

cout <<endl;
cout.width(7); //    after  every "width" effect there is association of previous "fill" effect
cout.precision(5);
cout<< sqrt((long double)2);

cout <<endl;

cout.width(15);
//cout.fill('#');
cout.precision(3);
cout.setf(ios::scientific,ios::floatfield);//printed like  1.234e+01
cout.setf(ios::internal,ios::adjustfield);
cout<<12.234567;

return 0;
}
