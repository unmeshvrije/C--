#include<iostream>
using namespace std;

void lib::dislib()
{
cout<<"The current status of library is :\n\t\t";
  for (int i = 0; i < 5; i++)
      {
        cout << "\n\t\t" << i + 1 << ")";
        cout << "\t" << c[i];
        cout << "\t" << flag[i];
      }
    getchar ();
    getchar ();
}
void lib::getdata()
{
    for (int i = 0; i < 5; i++)
      {
        cout << "\n\t\tEnter the name for book" << i + 1 << " :";
        cin >> c[i];
        flag[i] = "Not_issued";
      }
}
void lib::modify(int n,char b[])
{
        strcpy(c[n],b);
        flag[n] = "issued";
}
void lib::modifyr(int n,char b[])
{
        strcpy(c[n],b);
        flag[n] = "Not_issued";
}

void
Queue::Add (char n[])
{
  if (((end + 1) % size) == head)
    {
      cout << "\n\t\tQueuefull...";
      getchar ();
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
}                               //add fun end


int Queue::isempty()
{
if(head==-1 && end== -1)
return 1;
return 0;
}
void
Queue::display ()
{
  int temp = head;
cout<<"\n\t\tThe current status of waiting queue is :  \n\t";
  if (head == -1 && end == -1)
    {
      cout << "\n\t\tQueue empty...";
      getchar ();
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
      getchar ();
    }
}				//fun end


char*
Queue::deleteq ()
{
char temp[20];
strcpy(temp,q.name[head]);
  if (head == end)
    head = end = -1;

  else
    head = (head + 1) % size;
return temp;
}

