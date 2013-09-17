#include<iostream>
#include<stdlib.h>

using namespace std;
int menu ();
class staticq
{
  int head, end, size, cnt;
  char **name;

public:
    staticq ()			//constructor of queue
  {
    cnt = 0;
    size = 5;
    head = -1;
    end = -1;
    for (int i = 0; i < size; i++)
      name = new char *[i];

    for (int j = 0; j < size; j++)
        name[j] = new char[20];

  }				//end constr

  void Add ();
  void display ();
  void deleteq ();
//  int queuefull ();
};				//end of class

void
staticq::Add ()
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
      cout << "\n\t\tEnter the name: ";
      cin >> name[end];
    }
  else
    {
      cout << "\n\t\tEnter the name: ";
      end = (end + 1) % size;
      cin >> name[end];
      cnt++;
    }
}				//add fun end

void
staticq::display ()
{
  int temp = head;
/*while(temp <= end)
{
cout <<"\t"<<name[temp];
temp+=1;
}*/
  if (head == -1 && end == -1)
    {
      cout << "\n\t\tQueue empty...";
getchar();
getchar();
    }
  else
    {
      do
	{
	  cout << "\t" << name[temp];
	  temp = (temp + 1) % size;
	}
      while (temp != (end + 1) % size);


/*for(int i=head; (cnt==size && i!=end)||(cnt!=size && i!=end);i=(i+1)%size)
cout<<"\t"<< name[i];*/

      getchar ();
      getchar ();
    }
}				//fun end


void
staticq::deleteq ()
{
if(head==end)
head=end=-1;
else
head=(head+1)%size;
}



int
main ()
{
  staticq q1;

  int i, j, k, m, n, c;
  while ((c = menu ()) != 0)
    {
      if (c == 1)
	{
//add to the queue
	  q1.Add ();

//cout<<"\n\t\thiiiiiiiiiii";
	  getchar ();
	  getchar ();
	}
      else if (c == 2)
	{
//display
	  q1.display ();
	}

      else if (c == 3)
	{
//delete
	  q1.deleteq ();
	}

    }
  return 0;
}				//main


int
menu ()
{
  int c;
  system ("clear");
  cout << "\n\t\t0)Exit";
  cout << "\n\t\t1)Add to the queue";
  cout << "\n\t\t2)Display the queue";
  cout << "\n\t\t3)Delete from the queue";
  cout << "\n\t\tEnter your choice : ";
  cin >> c;
  return c;
}
