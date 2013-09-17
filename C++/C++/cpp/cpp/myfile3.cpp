#include<iostream>
#include<fstream>
#include<ios>
using namespace std;

class myfile
{
  fstream fp;
public:
  myfile (char *);
  void append ();
  void display ();
  void fileclose ();
};

void
myfile::fileclose ()
{
  fp.close ();
}

myfile::myfile (char *temp)
{
//cout<<temp;
  cout << "\n\t\tOpening the file...";

  fp.open(temp,ios::in|ios::out);
  int t = fp.rdstate();
  cout << " t =" << t;
if(t!=0)
{
cout<<"\n\t\tCan't open file";
fp.close();
fp.open(temp,ios::out);
t=fp.rdstate();
cout<<"\n\t\tt="<<t;
getchar();
getchar();
if(t!=0)
exit(0);
}
  getchar ();
}

void
myfile::append ()
{
  char data;
  fp.seekg (0, ios::end);

  cout << "\n\t\tEnter the characters : ";
  while ((data = getchar ()) != '~')
  fp.put(data);
}

void
myfile::display ()
{
  char data;
  fp.seekg (0,ios::beg);
  
while ( !fp.eof())
    {
      fp.get(data);
     if(!fp.eof())
      cout << data;
    }
}

int
menu ()
{
  int c;
  cout << "\n\t\t0)Exit";
  cout << "\n\t\t1)Append";
  cout << "\n\t\t2)Display";
  cout << "\n\t\tEnter choice";
  cin >> c;
  return c;
}

int
main ()
{
//myfile f("just.txt");
  int c;

  while ((c = menu ()) != 0)
    {
      myfile f ("temp.dat");

      switch (c)
	{
	case 1:
	  f.append ();
	  f.fileclose ();
	  break;

	case 2:
	  f.display ();
	  f.fileclose ();
	  break;

	default :break;
	}			//swi
    }				//whil
  return 0;
}				//main
