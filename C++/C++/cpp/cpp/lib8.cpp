#include<iostream>
using namespace std;

int menu ();

class lib
{
  int bno;

public:
  char **c, **flag;
  lib ()
  {
    for (int i = 0; i < 5; i++)
      {
	bno = i + 1;
	c = new char *[i];
        flag = new char *[i];
      }
    for (int i = 0; i < 5; i++)
      {
	c[i] = new char[20];
	flag[i] = new char[20];
      }

  }				//end of constr
void dislib();
void getdata();
void modify(int,char[]);
void modifyr(int,char[]);
//void returnbook(char[]);
};

void lib::dislib()
{
cout<<"\n\t\tThe current status of library is :\n\t\t";
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

class Queue
{
  int size;
  char **name;
friend class lib;
public:
int head,end;
    Queue ()		//constructer of queue class
  {
    size = 5;
      head = -1, end = -1;
//this will make head & end 0,0 and will start allowing- scanning the user names in the queue
    for (int i = 0; i < size; i++)
        name = new char *[i];

    for (int i = 0; i < size; i++)
        name[i] = new char[20];
	}

  void Add (char[]);
    void display ();
char* deleteq ();
int isempty();

};//queue class ends


void findbook(lib &l,Queue &q,char b[])
{
char temp[20];
int t2=0;
  for (int j = 0; j < 5; j++)
              {
			if(!(strcmp(b,l.c[j])))//if book is matched
		{
                   if (!(strcmp ("issued", l.flag[j])))     //book is  issued
                      {
			l.modifyr(j, l.c[j]);
			q.display();
			getchar ();
                        cout << "\n\t\t\tBook '" <<l.c[j]<< " 'is returned";
			getchar();
			l.dislib();
			getchar ();
//if q is not empty then only delete
t2=q.isempty();
getchar();
			if( t2==0 )//q is not empty
			{
			strcpy( temp, q.deleteq());
			cout<<"\n\t\tThe book '"<<l.c[j]<<"' is issued to "<< temp;
			q.display();
			getchar ();
			l.modify(j,l.c[j]);
			getchar ();
			l.dislib();
                        getchar ();
                        break;
			
			}
                        else break;
                      }
			else
			{
			cout<<"The book is already Non_issued";
			getchar();
			getchar();
			break;
			return;
			}
		}
	}
}	//end of findbook fun

void getname(lib &l,Queue &q)
{    
int ch, cntissued = 0;
    int flag_found = 0,flagissued=0;
    char nametemp[20];

cout<<"\n\t\thead="<< q.head<<"\n\t\tend="<<q.end;
      cout << "\n\t\tPlease enter your name  : ";
      cin >> nametemp;

	    for (int j = 0; j < 5; j++)
	      {
		   if (!(strcmp ("Not_issued", l.flag[j])))	//book is not issued
		      {
			flagissued=1;
			cout << "\n\t\t\tBook '" <<l.c[j]<< " 'is issued to you";
			l.modify(j, l.c[j]);			
			
			getchar ();
			getchar ();
			break;
		      }
		    else if(!strcmp("issued",l.flag[j]))
		      {
			cout << "\n\t\t Sorry!\n\t\t\t\tThe book '"<< l.c[j]  <<"' is already issued";
			continue;
		}  
	      }//for

if(flagissued==0)
{
cout<<" \n\t\tAll the books are issued\n\t\t\tYou have to wait in the queue";
q.Add (nametemp); 
}//name of usr,book-name

  } // getname     ends


static Queue q;
int
main ()
{
  int i,j,k,m,n,ch;
char tname[30];  
lib l;
l.getdata();
l.dislib();
  getchar ();
  getchar ();
  while ((ch = menu ()) != 0)
    {

      if (ch == 1)
	{
	    getname(l,q);
	  q.display ();
	  l.dislib();
	}
      if (ch == 2)
	{
cout <<"Enter the book-name you want to return :";
cin  >>tname;

findbook(l,q,tname);
	}

      if (ch == 3)
	{
	l.dislib();
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
}				//add fun end

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
