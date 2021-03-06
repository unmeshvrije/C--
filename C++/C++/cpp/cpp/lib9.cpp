#include "lib9.h"
Queue q;			//global decalration of queue class's obj
#include "lib9fun.cpp"
using namespace std;
int menu ();

void
findbook (lib & l, Queue & q, char b[])
{
  char temp[20];
  int t2 = 0;
  for (int j = 0; j < 5; j++)
    {
      if (!(strcmp (b, l.c[j])))	//if book is matched
	{
	  if (!(strcmp ("issued", l.flag[j])))	//book is  issued
	    {
	      l.modifyr (j, l.c[j]);
	      q.display ();
	      getchar ();
	      cout << "\n\t\t\tBook '" << l.c[j] << " 'is returned\n";
	      getchar ();
	      l.dislib ();
	      getchar ();
//if q is not empty then only delete
	      t2 = q.isempty ();
	      getchar ();
	      if (t2 == 0)	//q is not empty
		{
		  strcpy (temp, q.deleteq ());
		  cout << "\n\t\tThe book '" << l.
		    c[j] << "' is issued to " << temp << "\n";
		  q.display ();
		  getchar ();
		  l.modify (j, l.c[j]);
		  getchar ();
		  l.dislib ();
		  getchar ();
		  break;
		}
	      else
		break;
	    }
	  else
	    {
	      cout << "The book is already Non_issued";
	      getchar ();
	      getchar ();
	      break;
	      return;
	    }
	}
    }
}				//end of findbook fun

void
getname (lib & l, Queue & q)
{
  int ch, cntissued = 0;
  int flag_found = 0, flagissued = 0;
  char nametemp[20];

  cout << "\n\t\thead=" << q.head << "\n\t\tend=" << q.end;
  cout << "\n\t\tPlease enter your name  : ";
  cin >> nametemp;

  for (int j = 0; j < 5; j++)
    {
      if (!(strcmp ("Not_issued", l.flag[j])))	//book is not issued
	{
	  flagissued = 1;
	  cout << "\n\t\t\tBook '" << l.c[j] << " 'is issued to you";
	  l.modify (j, l.c[j]);

	  getchar ();
	  getchar ();
	  break;
	}
      else if (!strcmp ("issued", l.flag[j]))
	{
	  cout << "\n\t\t Sorry!\n\t\t\t\tThe book '" << l.
	    c[j] << "' is already issued";
	  continue;
	}
    }				//for

  if (flagissued == 0)
    {
      cout <<
	" \n\t\tAll the books are issued\n\t\t\tYou have to wait in the queue";
      q.Add (nametemp);
    }				//name of usr,book-name

}				// getname     ends

int
main ()
{
  int i, j, k, m, n, ch;
  char tname[30];
  lib l;
  l.getdata ();
  l.dislib ();
  getchar ();
  getchar ();
  while ((ch = menu ()) != 0)
    {

      if (ch == 1)
	{
	  getname (l, q);
	  q.display ();
	  l.dislib ();
	}
      if (ch == 2)
	{
	  cout << "Enter the book-name you want to return :";
	  cin >> tname;

	  findbook (l, q, tname);
	}

      if (ch == 3)
	{
	  l.dislib ();
	  getchar ();
	}

    }				//end while
  return 0;
}				//end main

int
menu ()
{
  int ch;
  system ("clear");
  cout << "\n\t\t0)Exit";
  cout << "\n\t\t1)Issue a book";
  cout << "\n\t\t2)Return a book";
  cout << "\n\t\t3)Display record of library";
  cout << "\n\t\tEnter the choice: ";
  cin >> ch;
  return ch;
}
