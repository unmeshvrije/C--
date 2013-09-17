#include<iostream>
using namespace std;
class date
{
  int dd, mm, yy;
public:
  void GetDate ();
  void PutDate ();
friend  void swap(date&,date&);
friend void calculate(date& ,date&);
friend void calculate(date& ,int);
  int calculatemaxdays ();
  int checkleap ();
};
void date::GetDate()
{
  cout << "\n\t\tEnter day month yy of date :";
  cin >> dd >> mm >> yy;
}

void
date::PutDate ()
{
 cout << "\n\t\tThe dates you have entered OR \n\n\t\tThe dates that are reached :" << endl;
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
calculate (date &d1,date&d2)
{
  int maxdays, cnt = 0, cntmonth = 0, cnty = 0;
  maxdays=d1.calculatemaxdays();  //will calculate days of this "month".
  while (d1.dd < d2.dd || d1.mm < d2.mm || d1.yy < d2.yy)
    {
      d1.dd++;
      cnt++;
      if (d1.dd > maxdays)
	{
	  d1.dd = 1;
	  d1.mm++;
	  maxdays = d1.calculatemaxdays ();
	  cntmonth++;
	  if (d1.mm > 12)
	    {
	      d1.mm = 1;
	      d1.yy++;
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
calculate(date &d,int n)
{
  int maxdays, lypr ,temp;
temp=n;
  maxdays = d.calculatemaxdays ();
  cout << endl << d.dd << "-" << d.mm << "-" << d.yy;
  getchar ();
  while (n != 0)
    {
      d.dd--;
      if (d.dd < 1)
	{
	  if ((d.mm == 7 ||d.mm==5) || (d.mm > 9 && d.mm % 2 == 0)) //condition must 
	    d.dd = 30;				//be reversed as current mm & next mm 
	  else if (d.mm == 3)			//will be different
	    {
	      if ((lypr = d.checkleap ()) == 1)
		d.dd = 29;
	      else
		d.dd = 28;
	    }
	  else
	    d.dd = 31;
	d.mm--;
	  maxdays = d.calculatemaxdays ();
	  if (d.mm < 1)
	    {
	      d.mm = 12;
	      d.yy--;
	    }
	}
      n--;
    }	//while loop ends
     cout<<"\n\t\tAfter subtracting '"<< temp<<"' days :\n\n\t\t";
      cout << "Date :" << d.dd << "-" << d.mm << "-" << d.yy << endl;
      getchar ();
}				//fun ends

void swap(date & d1,date &d2)
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
}
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
  while ((ch = menu ()) != 0)
    {
      switch (ch)
	{
	case 1:
	  d1.PutDate ();
	  d2.PutDate ();
		swap(d1,d2);//d1 should be  previous/ smaller   date
		  calculate (d1,d2);
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
calculate(d1,n);	//d1 should be small / previous date
else if(t==2)
calculate(d2,n);
	  break;
	default:
	  break;
	}			//switch
    }				//while
  return 0;
}				//main
