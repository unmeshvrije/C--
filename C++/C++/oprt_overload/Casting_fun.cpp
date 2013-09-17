#include <iostream>
using namespace std;


class Day;

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

   Year& operator = (Day &d);
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
  friend Year& Year::operator=(Day &);

};

ostream&
operator << (ostream& out, Day& day)
{
   out << day.d;
   return out;
}

Year&
Year::operator=(Day &day)
{
  //this is Year class's object
  cout << endl;
  cout << "In operator=() "<< endl;
  this->y = day.d / 365;
  return (*this);
}

int main()
{
  Year y = 2012;
  cout << y << endl;

  int i = 0,j = 0;
  j = y;
//operator int(this); this is object y
  cout << "j = " << j << endl;


  Day d = 730;
  cout << "d = " << d << endl;
  cout << "After y = d" << endl;
  i  = y = d;
  cout << "y = " << y << endl;
  cout << "And i = " << i << endl;
  return 0;
}
