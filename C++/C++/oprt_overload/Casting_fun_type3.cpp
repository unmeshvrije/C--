#include <iostream>
using namespace std;

class Year
{
   int y;
   public:
   Year(){}
   Year(int y)
   {
      this->y = y;
   }
   operator int()
   {
  cout << endl;
cout << "in CASTING function" << endl;     return y;
   }

   friend ostream& 
   operator <<(ostream &, Year &);

   //Year& operator = (Day &d);
   int operator =(int i)
   {
    cout << "operator=(int)" << endl;
      this->y =  i;
      return i;
   }
};

ostream&
operator <<(ostream &out, Year &year)
{
   out << year.y;
   return out;
}

class Day
{
   int d;
   public:
   Day(){}
   Day(int d){this->d = d;}
   friend ostream&
   operator << (ostream&, Day&);

   operator int ()
   {
  cout << "Day's CASTING fun" << endl;
      return (d/365);
   }
  //friend Year& Year::operator=(Day &);

};

ostream&
operator << (ostream& out, Day& day)
{
   out << day.d;
   return out;
}
/*
Year&
Year::operator=(Day &day)
{
  //this is Year class's object
  cout << endl;
  cout << "In operator=() "<< endl;
  this->y = day.d / 365;
  return (*this);
}*/

int main()
{
  Year y;
  int i =0;
  Day d = 730;
  cout << "d = " << d << endl;
  cout << "After y = d" << endl;
  i  = y = d;
  /*y = Day's operator int() will give
  y = (730/365)
  y = 2
this will expand to 
  y.operator=(int)
*/
  cout << "y = " << y << endl;
  cout << "And i = " << i << endl;
  return 0;
}
