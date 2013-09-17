#include<iostream>
#include<fstream>
#include<iomanip>
#define MAX 12
using namespace std;		//purpose of fn ?

class File
{
  fstream fp;
  char fn[MAX];
public:
    File (char *);
    File(char*,long int flag);
    File ();
    void display ();
   File& operator+(File&); 
//File& operator=(File&);
};
/*File::File(char *temp,long int flag)
{
strcpy(fn,temp);
fp.open(fn,flag);
int t=fp.rdstate();
cout<<t;
}*/


/*File& File::operator=(File &f2)
{
//1File temp;
strcpy(fn,f2.fn);
fp=f2.fp;
}*/

File::File (){}

File::File (char *temp)
{
strcpy(fn,temp);

  fp.open (fn,ios::in);
  int t;
  if ((t = fp.rdstate ()) != 0)
    {
      int i = 0;
      cout << "\n\t\tNot properly opened in read mode : ";
      fp.clear ();
      fp.open (temp, ios::out);
      t = fp.rdstate ();
      cout << "\nt=" << t;
      char c;
      while ((c = getchar ()) != '~')
	{
	  fp.put (c);
	  fn[++i] = c;
	}
    }
  else				//file already exists
    {
      char c;
      int i = 0;
      fp.seekg (0, ios::beg);
      while (!fp.eof ())
	{
	  fp.get (c);
	  if (!fp.eof ())
	    {
//	      fn[++i] = c;
	      cout << c;
	    }
	}
    }				//else
  fp.close ();
//fp.open(fn,ios::in | ios::out);
//t=fp.rdstate();
//cout<<"\n\t\tt="<<t;
}

/*void
File::display ()
{
char c;
//cout<<"hiiiiiiiiiiiii";
fp.open(fn,ios::in);
int t=fp.rdstate();
cout<<"\n\t\tt="<<t;
getchar();
fp.seekg(0,ios::beg);
while(!fp.eof())
{
fp.get(c);
if(!fp.eof())
cout<<c;
}
fp.close();
//fp.open (fn, ios::in | ios::out);
}*/

File& File::operator+(File &f2)
{  
	// f1 will be "this" & f2 is passed
char c;
File temp("temp.txt",ios::out);
int t=fp.rdstate();
cout<<"\n\t\tt= "<<t;
	while(!fp.eof())
	{
		fp.get(c);
		if(!fp.eof())
		  temp.fp << c;
	}
fp.close();

f2.fp.open(f2.fn,ios::in);
	
	while(!(f2.fp).eof())
	{
		(f2.fp).get(c);
		if(!(f2.fp).eof())
		  temp.fp << c;
	}
(f2.fp).close();

return temp;
}

main ()
{
  char n1[20], n2[20];
  cout << "\n\t\tEnter filename : ";
  cin >> n1;
  cout << "\n\t\tEnter filename : ";
  cin >> n2;

  File f1 ("f1.txt");
  File f2 ("f2.txt");
//  f1.display ();
File f3;
f3=f1+f2;
//f3=f1+f2;
}
