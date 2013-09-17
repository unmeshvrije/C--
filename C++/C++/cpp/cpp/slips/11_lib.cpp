#include<iostream>
#include<string.h>
using namespace std;

class Queue
{
  int size;
  char name[5][20];
public:
  int head, end;
    Queue ()	//constructer of queue class
  {
    size = 5;
    head = -1, end = -1;
  }
  void Add (char[]);
  void display ();
  char *deleteq ();
  int isempty ();
};				//queue class end
Queue q;			//global decalration of queue class's obj

void
Queue::Add (char n[])
{
  if (((end + 1) % size) == head)
    {
      cout << "\n\t\tQueuefull...";
      getchar ();
      return;
    }
  if ((head == -1) && (end == -1))
    {
      head = end = 0;
      strcpy (name[end], n);
    }
  else
    {
      end = (end + 1) % size;
      strcpy (name[end], n);
    }
}				//add fun end
int
Queue::isempty ()
{
  if (head == -1 && end == -1)
    return 1;
  return 0;
}

void
Queue::display ()
{
  int temp = head;
  cout << "\n\t\tThe current status of waiting queue is :  \n\t";
  if (head == -1 && end == -1)
    {
      cout << "\n\t\tQueue empty...";
      getchar ();
    }
  else
    {
      cout << "[";
      do
	{
	  cout << "\t" << name[temp];
	  temp = (temp + 1) % size;
	}
      while (temp != (end + 1) % size);
      cout << "]";
      getchar ();
    }
}				//fun end
char *
Queue::deleteq ()
{
  char temp[20];
  strcpy (temp, q.name[head]);
  if (head == end)
    head = end = -1;
  else
    head = (head + 1) % size;
  return temp;
}

int
menu ()
{
  int ch;
  cout << "\n\t\t0)Exit";
  cout << "\n\t\t1)Issue a book";
  cout << "\n\t\t2)Return a book";
  cout << "\n\t\t3)Display waiting queue";
  cout << "\n\t\tEnter the choice: ";
  cin >> ch;
  return ch;
}

main ()
{
  int i, j, k, m, n, ch, bkcnt = 0;
  char *tname;
  while ((ch = menu ()) != 0)
    {
      switch (ch)
	{
	case 1:
	  cout << "\n\t\tEnter the name :";
	  cin >> tname;
	  if (bkcnt < 5)
	    {
	      cout << "\n\n\t\tBook is issued to you.";
	      bkcnt++;
	      getchar ();
	    }
	  else
	    {
	      cout << "\n\nSorry!\n\t\t\tYou have to wait in the Queue.";
	      getchar ();
	      q.Add (tname);
	    }
	  break;
	case 2:
	  bkcnt--;
	  if ((q.isempty ()) == 0)//if not empty
	    {
	      strcpy (tname, q.deleteq ());
	      cout << "\n\t\tThe book is issued to " << tname;
	      bkcnt++;
	      getchar ();
	    }
	  else
	    cout << "The book is not issued to anyone.";
	  break;
	case 3:	  q.display ();	  break;
	}			//switch
    }				//end while
}				//end main
