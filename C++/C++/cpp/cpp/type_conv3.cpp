#include<iostream>
using namespace std;

/*
struct node
{
  int data;//by default public
}

struct node s;
s.data  =10;
*/
/* user defined type to another 
   user defined type.
*/
class year;

class day
{
	//private data member
	int dd;
	public:
	day(){dd=365;}

	int getday()
	{
	  return dd;
	}

friend ostream& operator<<(ostream & ,day &d);

/*
void operator=(int t) //operator overloading function
{
	dd=t;
}
*/

void operator=(year &);

};

ostream& operator<<(ostream & out ,day &d)
{
out<< d.dd ;
return out;
}

class year
{

int yy;	
	public:

	int getyy()
	{
	  return yy;
	}
	year()
	{
		yy=10;
	}
	year(int t)
	{
		yy=t;
	}

	year(day &d)
	{
	 yy= d.getday()/365; //type conversion actually in the constructor
	}

/*	operator int()
	{
	return yy*365;
	}
	*/
friend ostream& operator<<(ostream & ,year &);
};


void day::operator=(year& y)
{
  dd  = y.getyy() *365;
}

ostream& operator<<(ostream & out ,year &y)
{
out<< y.yy ;
return out;
}

main()
{
year y;
cout<<"\n  Initially...... y => "<<y;
day d;
y=d;
cout<<"\n  After assigning 365 days to y =>"<< y;

      //this will run casting function in year class 
d=y; //   "operator overloading function" has to be written in this case
    //	since casting function would return integer and we have to convert it into "day" type
cout<<endl<<d;

year y2(3);
day d2;
d2=y2;

cout<<endl<<"d2 is: "<<d2;

}
