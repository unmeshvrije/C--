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
  void subtract (int);
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
    }				//while loop ends

  cout << "\n\n\t\tThe difference b2n the days of the dates :" << cnt;
  cout << "\n\n\t\tThe difference b2n the months of the dates :" << cntmonth;
  cout << "\n\n\t\tThe difference b2n the years of the dates :" << cnty;
}				//fun ends

void
date::subtract (int n)
{
  int maxdays, lypr;
  maxdays = date::calculatemaxdays ();
  cout << maxdays;
  cout << endl << dd << "-" << mm << "-" << yy;
  getchar ();
  while (n != 0)
    {
      dd--;
      if (dd < 1)
	{
	  if ((mm!=1 && mm!=3 &&mm <= 7 && mm % 2 == 1) || (mm > 7 && mm % 2 == 0)) //condition must 
	    dd = 30;				//be reversed as current mm & next mm 
	  else if (mm == 3)			//will be different
	    {
	      if ((lypr = checkleap ()) == 1)
		dd = 29;
	      else
		dd = 28;
	    }
	  else
	    dd = 31;
	  mm--;
	  maxdays = date::calculatemaxdays ();
	  if (mm < 1)
	    {
	      mm = 12;
	      yy--;
	    }
	}
      cout << "Date :" << dd << "-" << mm << "-" << yy << endl;
      n--;
      getchar ();
    }				//while loop ends

  //cout << "\n\n\t\tThe difference b2n the days of the dates :" << cnt;
//  cout << "\n\n\t\tThe difference b2n the months of the dates :" << cntmonth;
//  cout << "\n\n\t\tThe difference b2n the years of the dates :" << cnty;
}				//fun ends
int
menu ()
{
  int ch;
  system ("clear");
  cout << "\n\t\t0)Exit";
  cout << "\n\t\t1)Number of days";
  cout << "\n\t\t2)Subtract days from the date";
  cout << "\n\t\tEnter the choice: ";
  cin >> ch;
  return ch;
}


int
main ()
{
  date d1, d2;
  int n, ch, t1, t2;
  system ("clear");
  d1.GetDate ();
  d2.GetDate ();
  while ((ch = menu ()) != 0)
    {
      switch (ch)
	{
	case 1:
	  cout << "\n\t\tThe dates you have entered :" << endl;
	  d1.PutDate ();
	  d2.PutDate ();
	  t1 = d1.validate ();
	  t2 = d2.validate ();
	  if (t1 == 1)
	    {
	      if (t2 == 1)
		{

		  if (d1.yy > d2.yy)
		    {
		      date temp;
		      temp = d1;
		      d1 = d2;
		      d2 = temp;
		    }
		  else
		    {
		      if ((d1.yy == d2.yy) && (d1.mm > d2.mm))
			{
			  date temp;
			  temp = d1;
			  d1 = d2;
			  d2 = temp;
			}
		      else
			{
			  if ((d1.yy == d2.yy) && (d1.mm == d2.mm)
			      && (d1.dd > d2.dd))
			    {
			      date temp;
			      temp = d1;
			      d1 = d2;
			      d2 = temp;
			    }
			}
		    }
d1.PutDate();
d2.PutDate();
getchar();
		  d1.calculate (d2.dd, d2.mm, d2.yy);	//d1 should be small / previous date
		  getchar ();
		}		//t2
	      else
		cout << "\n\t\tSecond date is invalid";
	    }			//t1
	  else
	    cout << "\n\t\tFirst date is invalid";
	  getchar ();
	  break;

	case 2:
cout<<"\n\t\tHow many days do you want to subtract : ";
cin>>n;
d1.PutDate();
d2.PutDate();
cout<<"\n\tEnter date no from which you want to subtract the days\n";
cout<<"\n\t\tPress 1)first\n\t\tPress2)Second";
int t;
cin>>t;
if(t==1)
d1.subtract (n);	//d1 should be small / previous date
else if(t==2)
d2.subtract (n);
	  break;

	default:
	  break;

	}			//switch

    }				//while

  return 0;
}				//main
