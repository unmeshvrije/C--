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
  cout << "\n\t\tOpening the file...\n\n";

  fp.open(temp,ios::in);
  int t = fp.rdstate();
  cout << " fp.rdstate() =" << t <<"\n\n";
if(t!=0)
{
cout<<"\n\t\tCan't open file int read mode\n\n " ;
fp.clear();
fp.open(temp,ios::out);
t=fp.rdstate();
cout<<"\n\t\tReturn value of function rdstate() ="<<t<<"\n\n";
getchar();
getchar();
if(t!=0)
exit(0);
}
fp.close();
fp.open(temp,ios::in|ios::out);
}

void
myfile::append ()
{
  char data;
  fp.seekg (0, ios::end);
  cout << "\n\t\tEnter the characters \n\n\t\t '~' is termination character: ";
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
	  cout<<"\n\t\tHere is the file ........\n";
	  f.display ();
	  f.fileclose ();
	  break;
	default :break;
	}			//swi
    }				//whil
  return 0;
}				//main
