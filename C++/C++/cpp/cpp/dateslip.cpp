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
  void calculate(int);
};
void date::GetDate()
{
  cout << "\n\t\tEnter day month yy of date :";
  cin >> dd >> mm >> yy;
}

void
date::PutDate ()
{
  cout << "\n\t" << dd << "-" << mm << "-" << yy;
}

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
date::calculate (int dd1,int mm1,int yy1)
{
  int maxdays, cnt = 0, cntmonth = 0, cnty = 0;
  maxdays=calculatemaxdays();  //will calculate days of this "month".
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
    }				//while loop ends
  cout << "\n\n\t\tThe difference b2n the days of the dates :" << cnt;
  cout << "\n\n\t\tThe difference b2n the months of the dates :" << cntmonth;
  cout << "\n\n\t\tThe difference b2n the years of the dates :" << cnty;
getchar();
}				//fun ends

void
date::calculate(int n)
{
  int maxdays, lypr ,temp;
temp=n;
  maxdays = date::calculatemaxdays ();
  cout << endl << dd << "-" << mm << "-" << yy;
  getchar ();
  while (n != 0)
    {
      dd--;
      if (dd < 1)
	{
	  if ((mm == 7 ||mm==5) || (mm > 9 && mm % 2 == 0)) //condition must 
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
      n--;
    }	//while loop ends
     cout<<"\n\t\tAfter subtracting '"<< temp<<"' days :\n\n\t\t";
      cout << "Date :" << dd << "-" << mm << "-" << yy << endl;
      getchar ();
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
  date d1, d2,temp1,temp2;
  int n, ch, t1, t2;
  system ("clear");
  d1.GetDate ();
  d2.GetDate ();
  temp1=d1;
  temp2=d2;
  while ((ch = menu ()) != 0)
    {
      switch (ch)
	{
	case 1:
	  cout << "\n\t\tThe dates you have entered :" << endl;
	  d1.PutDate ();
	  d2.PutDate ();
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
		
		  d1.calculate (d2.dd, d2.mm, d2.yy);	//d1 should be small / previous date
		  getchar ();
		  getchar ();
	  getchar ();
	  break;
	case 2:
cout<<"\n\t\tHow many days do you want to subtract : ";
cin>>n;
temp1.PutDate();
temp2.PutDate();
cout<<"\n\tEnter date no from which you want to subtract the days\n";
cout<<"\n\t\tPress 1)first\n\t\tPress2)Second";
int t;
cin>>t;
if(t==1)
temp1.calculate(n);	//d1 should be small / previous date
else if(t==2)
temp2.calculate(n);
	  break;

	default:
	  break;
	}			//switch
    }				//while
  return 0;
}				//main
