#include<iostream>
using namespace std;

class date
{
public:
  int dd, mm, yy;


  void GetDate ();
  void PutDate ();
  void calculate (int, int, int);
  int calculatemaxdays ();
  int checkleap ();
  int validate ();
  int validateyear ();
  int validatemonth ();
  int validateday ();
  //int nod (date &, date &);
};

int
date::validate ()
{
  int temp1 = date::validateyear ();
  int temp2 = date::validatemonth ();
  int temp3 = date::validateday ();

  if (temp1 == 1 && temp2 == 1 && temp3 == 1)
    return 1;
  return 0;
}

int
date::validateyear ()
{
  if (this->yy < 1900 || this->yy > 2000)
    {
      cout << "\n\t\tInvalid year.";
      return 0;
    }
  return 1;

}

int
date::validatemonth ()
{
  if (mm < 1 || mm > 12)
    {
      cout << "\n\t\tInvalid month";
      return 0;
    }
  return 1;
}

int
date::validateday ()
{
  int lpyr = 0;
  if (mm == 2)
    {
      lpyr = date::checkleap ();
      if (lpyr == 1)
	{
	  if (dd > 29)
	    {
	      cout << "\n\t\tIn leap yr feb can't have >29 days";
	      return 0;
	    }
	  return 1;
	}
      else			//if nonleap yr
	{
	  if (dd > 28)
	    {
	      cout << "\n\t\tIn non-leap yr feb can't have >28 days";
	      return 0;
	    }
	  return 1;
	}
    }
  else if ((mm <= 7 && mm % 2 == 1) || (mm > 7 && mm % 2 == 0))
    {
      if (dd > 31)
	{
	  cout << "\n\t\tInvalid day";
	  return 0;
	}
      return 1;
    }
  else
    {
      if (dd > 30)
	{
	  cout << "\n\t\tInvalid day";
	  return 0;
	}
      return 1;
    }

}


void
date::GetDate ()
{
  cout << "\n\t\tEnter day month yy of date :";
  cin >> dd >> mm >> yy;
}

void
date::PutDate ()
{
  cout << "\n\t" << dd << "-" << mm << "-" << yy;
}

/*	Aditi's logoc*/

int
date::calculatemaxdays ()
{
  int maxdays = 31;
  int lpyr;

  if (mm == 2)
    {
      lpyr = date::checkleap ();
      if (lpyr == 1)
	maxdays = 29;
      else
	maxdays = 28;
    }
  if (mm == 4 || mm == 6 || mm == 9 || mm == 11)
    maxdays = 30;

  return maxdays;
}

int
date::checkleap ()
{
  if (yy % 4 == 0)
    {
      if (yy % 100 == 0)
	{
	  if (yy % 400 == 0)
	    return 1;
	  else
	    return 0;
	}
      return 0;
    }
  return 0;
}				//eof


void
date::calculate (int dd1, int mm1, int yy1)
{
  int maxdays, cnt = 0, cntmonth = 0, cnty = 0;

  maxdays = date::calculatemaxdays ();
  cout << maxdays;

  while (dd < dd1 || mm < mm1 || yy < yy1)
    {
      dd++;
      cnt++;
      if (dd > maxdays)
	{
	  dd = 1;
	  mm++;
	  maxdays = date::calculatemaxdays ();
	  cntmonth++;
	  if (mm > 12)
	    {
	      mm = 1;
	      yy++;
	      cnty++;
	    }
	}
      cout << "Date :" << dd << "-" << mm << "-" << yy << endl;
    }

  cout << "\n\n\t\tThe difference b2n the days of the dates :" << cnt;
  cout << "\n\n\t\tThe difference b2n the months of the dates :" << cntmonth;
  cout << "\n\n\t\tThe difference b2n the years of the dates :" << cnty;
}				//fun ends








/*		Rohit's logic

int
nod (date & d1, date & d2)
{
  int d, m, y;
  if (d1.d < d2.d)
    {
      d1.m--;
      if (d1.m == 0)
	  d1.m == 12;
	  d1.y--;
	       if (d1.m == 2)
		  if (d1.y % 4 == 0 && d1.y % 40 != 0)
	    d = d1.d - d2.d + 29;
	  else
	    d = d1.d - d2.d + 28;
	
      else if ((d1.m % 2 == 0 && d1.m > 7) || (d1.m % 2 == 1 && d1.m <= 7))
	d = d1.d - d2.d + 31;
      else
	d = d1.d - d2.d + 30;
    }
  else
    {
         d = d1.d - d2.d;
      for (m = d2.m; m != d1.m; m++)
	
	  if (m == 13)
	      m = 1;
	      d1.y--;
	  if (m == 2)
		      if (d1.y % 4 == 0 && d1.y % 40 != 0)
		d = d + 29;
	      else
		d = d + 28;
	
	  else if ((m % 2 == 0 && m > 7) || (m % 2 == 1 && m <= 7))
	    d = d + 31;
	  else
	    d = d + 30;
	
}
      for (y = d2.y + 1; y <= d1.y; y++)
	{
	  if (y % 4 == 0 && y % 40 == 0)
	    d = d + 366;
	  else
	    d = d + 365;

	  return d;
	}
    }*/




int
menu ()
{
  int ch;
system("clear");
  cout << "\n\t\t0)Exit";
  cout << "\n\t\t1)Number of days";
  cout << "\n\t\t2)Subtract days from the date";
cout<<"\n\t\tEnter the choice: ";
cin>>ch;
  return ch;
}


int
main ()
{
  date d1, d2;
  int n, ch,t1,t2;
system("clear");
  d1.GetDate ();
  d2.GetDate ();
  while ( (ch = menu ()) != 0)
    {

      switch (ch)
	{

	case 1:

  d1.PutDate ();
  d2.PutDate ();
	   t1 = d1.validate ();
	   t2 = d2.validate ();
	  cout << t1 << endl << t2;
getchar();
getchar();
    d1.calculate (d2.dd, d2.mm, d2.yy);
getchar();
	  break;

	case 2:
	  break;

	default:
	  break;

	}			//switch

    }				//while

  return 0;
}
