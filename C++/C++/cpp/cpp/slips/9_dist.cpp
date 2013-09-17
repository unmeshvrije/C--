#include<iostream>
using namespace std;

class dist2;

class dist1
{
  private:
   int foot,inch;
   public:
    void accept()
    {
     cout <<endl << "Enter Feet : ";cin >>foot;
     cout <<endl << "Enter inches : ";cin >>inch;
    } 
  
    friend void add(dist1& ,dist2& );
};

class dist2
{
  private:
   int meter,centimeter;
   public:
     void accept()
    {
     cout <<endl << "Enter meter : ";cin >>meter;
     cout <<endl << "Enter centimeter : ";cin >>centimeter;
    } 
    friend void add(dist1& ,dist2& );
};

void add(dist1& d1,dist2& d2)
{
 float  cm,inches;
 cm = ( d2.meter*100) + d2.centimeter;
 inches = (d1.foot*12) + d1.inch;
 
 // final addition in centimeter
 cm +=  inches *2.5;
 cout << endl << (int)(cm/100) << "meters" <<"," << ((int)cm) % 100 <<" centimeters";
 cout << endl << "In feet \n " << (int)((cm/2.5 ) )/12 << " feet, " << (int)((cm/2.5 ) )%12 << " inches ";
}
main()
{
  dist1 d1;
  dist2 d2;
  d1.accept();
  d2.accept();
  add(d1,d2);
}


