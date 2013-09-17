#include<iostream>
#include<fstream>
#include<unistd.h>
#include<stdio.h>
using namespace std;

int cnt = 0;
class emp
{
  int id, sal;
  char name[20];

public:
  void getdata ();
  int putdata ();
};

int not_repeating_id(int temp_id)
{
int id,sal;
char name[20];
ifstream temp;
temp.open("emp.txt",ios::in);
while(!temp.eof())
{
temp >>id>>name>>sal;
if(id==temp_id)
{
temp.close();
return 0;
}
}
//if not repeating
temp.close();
return 1;
}
void
emp::getdata ()
{
  int id, sal;
  char name[20];
  cout << "\nEnter : ";
  cin >> id >> name >> sal;
int t;
//t=e.putdata();
//if(t==0)
  ofstream fout;
  fout.open ("emp.txt", ios::app);
if( (not_repeating_id(id))==1)
{
  fout << "\n" << id << "\t" << name << "\t" << sal;
  fout.close ();
}
else
{
cout<<"\n\t\tNot allowed.";
}
}



int
emp::putdata ()
{
  int id, sal;
  char name[20];
  ifstream fin;

  fin.open ("emp.txt", ios::in);

  int c = fin.rdstate ();
  cout << c;
  getchar ();
  if (c != 0)
    {
      cout << "File is not created yet.";
      return 0;
    }
  else
    {

      int cnt = 0;
      while (!fin.eof ())
	{
	  cnt++;
	  fin >> id >> name >> sal;
	  cout << "\n" << id << "\t" << name << "\t" << sal;
	}
      fin.close ();
      cout << "\n\n\t\tcnt=" << cnt;
    }
  return cnt;
}

int
menu ()
{
  int c;
  cout << "\n\t\t0)Exit";
  cout << "\n\t\t1)Append";
  cout << "\n\t\t2)Display";
  cout << "\n\t\t3)Delete";
  cout << "\n\t\t4)Modify";
  cout << "\n\t\tEnter choice";
  cin >> c;
  return c;
}

void
find (int n, emp & e)
{
  int id, sal,flag_found=0;
  char name[20];

  ifstream fp;
  fp.open ("emp.txt", ios::in);

  ofstream temp;
  while (!fp.eof ())
    {
      fp >> id >> name >> sal;
      if (id != n)
	{
	  temp.open ("t.txt", ios::app);
	  temp << "\n" << id << "\t" << name << "\t" << sal;
	  temp.close ();
	}
	else
	flag_found=1;
    }
  fp.close ();

if(flag_found==0)
{
cout<<"\n\t\tThe employee having id ("<< n<<") is not in the file";
return ;
}
int u2=e.putdata();

if( u2==1)//only 1 record
{
int u3=remove("emp.txt");
cout<<"\n\n\t\thiiiiiiu3="<<u3;
getchar();
getchar();
return ;}

  int s = remove ("emp.txt");
  cout << "\n\t\ts=" << s;

  int just;
  just = e.putdata ();		//as expected the file is now empty here "just" receives 0
  cout << "\n\n\t\tjust=" << just<<" records in the file 'emp.txt'";

/*Now we want to rename the file "t.txt" as emp.txt*/
  ofstream fp1;
  fp1.open ("emp.txt", ios::app);
  ifstream temp2;
  temp2.open ("t.txt", ios::in);

int u1=temp2.rdstate();
cout<<"\n\t\tu1="<<u1;
  
while (!temp2.eof ())
    {
      temp2 >> id>> name>> sal;
      fp1 << "\n" << id << "\t" << name<< "\t" << sal;
    }
  temp2.close ();
  fp1.close ();
  int t2 = remove ("t.txt");

  cout << "\n\t\tIndication of the deletion of the file t.txt :" << t2;
  return;
}

int
main ()
{
  int c;
  emp e;
  while ((c = menu ()) != 0)
    {
      switch (c)
	{
	case 1:
	  e.getdata ();
	  break;

	case 2:
	  int m;
	  m = e.putdata ();
	  break;

	case 3:		//delete
	  cout << "\n\t\tEnter id";
	  int n;
	  cin >> n;
	  int t;
	  t = e.putdata ();
	  find (n, e);

	  break;

	case 4:		//modify
	  break;

	default:
	  break;
	}			//swi

    }				//while

  return 0;
}
