#include<iostream>
using namespace std;

class Table
{
  public : Table(){cout << endl <<"constr";}
  public : ~Table(){cout << endl <<"destr";}
};

void f(void)
{
  Table t5;
}


main()
{
Table t1;Table t2 = t1;
f();
Table t3;
 t3 = t2;
}
