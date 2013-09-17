#include<iostream>
#include<ios>
#include<fstream>
#include<iomanip>
using namespace std;

class item
{
  int item_no, qty;
  char name[20];
  float price;

public:
  void getitem ();
  int putitem (int);

};
void
item::getitem ()
{
  cout << "\n\t\tenter item info :\n";
do
 {
	cout<<"enter positive item no : ";
	 cin >> item_no ;
}while(item_no<=0);

 // cout<<"\n\t\t Enter name:\t\tQty\t\tPrice"; 
  cin>> name >> qty >> price;
  ofstream write ("item.txt", ios::app);//opening file in append mode
  write << "\n" << item_no << "\t" << name << "\t" << qty << "\t" << price;
  write.close ();
}

int
item::putitem (int n)
{
  int cnt1 = 0, cnt2 = 0, flag_end = 0;
  ifstream read ("item.txt");//opening the file in read mode

  while (!read.eof () && (++cnt1 <= n))     //condition for skipping n-1 records
    {
      read >> item_no >> name >> qty >> price;
      if (read.eof () && cnt1 == n)//if final record is to be printed
	{
	  flag_end = 1;
	  read.seekg ('\r', ios::cur);//we've to come back to the start of the last record
	  break;
	}
    }//end of while
  if (!read.eof ())//if end hasn't encountered
    {
      cout << "\nItem_number\tItem_name\tQuantity\tPrice";
      cout << "\n" << setw (11) << item_no << "\t" << setw (9) << name << "\t"
	<< setw (8) << qty << "\t" << setw (5) << price;
      cnt2++;
    }
  if (flag_end == 1)//last record read condition
    {
      cout << "\nItem_number\tItem_name\tQuantity\tPrice";
      cout << "\n" << setw (11) << item_no << "\t" << setw (9) << name << "\t"
	<< setw (8) << qty << "\t" << setw (5) << price;
      cnt2++;
    }
  read.close ();
	getchar();
	getchar();
  return cnt2;
}

int
menu ()
{
  int ch;
  system("clear");
  cout << "\n\t\t0)Exit";
  cout << "\n\t\t1)Add a record";
  cout << "\n\t\t2)Retrieve nth record";
  cout << "\n\t\tEnter the choice";
  cin >> ch;
  return ch;
}

int
main ()
{
  int ch, j, k;
  item i;
  system("clear");
  while ((ch = menu ()) != 0)
    {
      switch (ch)
	{
	case 1:
	  i.getitem ();
	  break;

	case 2:
	  int n, ans;
	  do
	  {cout<<"\nenter n : ";
	    cin >> n;}		
	  while (n <= 0);

	  ans = i.putitem (n);

	  if (ans == 0)
	    {cout << "\n\t\tThe record does not exist\n\n";
		getchar();}
	  break;

	default:
	  break;
	}			//swi
    }				//while
  return 0;
}				//main
