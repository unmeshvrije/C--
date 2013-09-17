#include<iostream>
#include<fstream>
#include<ios>
#include<iomanip>
using namespace std;
fstream fp;			//very imp to have global pointer like this as this is accessing 				   all the file records
class student
{
  int roll;
  char name[20], p[20], fe[20], be[20];
public:
    student ();
   ~student ();
  void putdata ();
  void getdata ();
  int getroll ();
};

void
student::getdata ()
{
  cout << "\n\t\tEnter roll";
  cin >> roll;
  cout << "\n\t\tEnter name";
  cin >> name;
  cout << "\n\t\tEnter proj";
  cin >> p;
  cout << "\n\t\tEnter fe";
  cin >> fe;
  cout << "\n\t\tEnter be";
  cin >> be;
}

int
student::getroll ()
{
  return roll;
}

void
student::putdata ()
{
  cout << "\n" << roll << "\t" << name << "\t" << p << "\t" << fe << "\t" <<
    be;
}

student::student ()
{
  fp >> roll >> name >> p >> fe >> be;	//directly  accept in student's data 
  // "n" records so fp will move dowmwards in file 4times
}

student::~student ()
{
  fp <<"\n"<< roll << "\t" << name << "\t" << p << "\t" << fe << "\t" << be;
}

int
menu ()
{
  int ch;
  cout << "\n\t\t0)Exit";
  cout << "\n\t\t1)Display all details";
  cout << "\n\t\t2)Details of a single student";
  cout << "\n\t\t3)Modify details of a student";
  cout << "\n\t\tEnter the choice : ";
  cin >> ch;
  return ch;
}

int main ()
{
  int ch, n, i, key,temp,t;
  student *s;
  fp.open ("student.txt", ios::in | ios::out);
    fp >> n;
  s = new student[n];		//allocating memory of 'n' students to the ptr of class student

  while ((ch = menu ()) != 0)
    {
      switch (ch)
	{
	case 1:
	  for (i = 0; i < n; i++)
	    s[i].putdata ();
	  break;

	case 2:
	  cout << "\n\t\tEnter the roll ";
	  cin >> key;
	  for (i = 0; i < n; i++)
	    {
	      if ((s[i].getroll ()) == key)
		s[i].putdata ();
	    }
	  if (i == n)
	    cout << "\n\n\t\tThe record not found.";
	  getchar ();
	  break;
	case 3:
	  cout << "\n\t\tEnter roll whose record you want to modify : ";
	  cin >> key;
	  for (i = 0; i < n; i++)
	    {
	      if ((s[i].getroll ()) == key)
		s[i].getdata ();
	    }
	  if (i == n)
	    cout << "\n\t\tRecord not found.";
	  break;
	default:
	  cout << "\n\t\tInvalid Choice";
	  break;
	}			//swi
    }				//while
  fp.close ();
temp=fp.rdstate();
cout<<"\nt="<<temp;
getchar();
  fp.open("student.txt",ios::out);
temp=fp.rdstate();
cout<<"\nt="<<temp;
getchar();
  fp << n;
cout<<"calling destructor..............";
  for (i = 0; i < n; i++)
  delete (s+i);//  s[i].~student();

  fp.close ();
  return 0;
}				//main
