#include<iostream>
using namespace std;

class person
{
protected:
  int id;
  char name[20];
public:
     virtual void accept ()  {}
     virtual void display () {}
};

class teaching:public virtual person
{
protected:
  char sub[20];
public:
   void accept ();
   void display ();
};

void
teaching::accept ()
{
  cout << "\n\t\tEnter id: ";
  cin >> id;
  cout << "\n\t\tEnter name: ";
  cin >> name;
  cout << "\n\t\tEnter sub: ";
  cin >> sub;
}

void
teaching::display ()
{
  cout << "\n" << id << "\t" << name << "\t" << sub << "(teaching)";
}

class nonteaching:public virtual person
{
protected:
  char dept[20];
public:
   void accept ();
   void display ();

};
void
nonteaching::accept ()
{
  cout << "\n\t\tEnter id: ";
  cin >> id;
  cout << "\n\t\tEnter name: ";
  cin >> name;
  cout << "\n\t\tEnter dept: ";
  cin >> dept;
}

void
nonteaching::display ()
{
  cout << "\n" << id << "\t" << name << "\t" << dept << "(nonteaching)";
}

class instructor:public teaching, public nonteaching
{
  char sp[20];
public:
  void accept ()
  {
    cout << "\n\t\tEnter inst sp : ";
    cin >> sp;
  }
  void display ()
  {
    cout << "\t" << sp;
  }
};

main ()
{
/*
  int n,j,ch;
  instructor *i;
  cout <<endl << " enter how many iuns : ";
  cin >> n;

  i = new instructor[n];
  for(j=0;j<n;j++)
  {
     cout << "\n\t\tteching or non  \n\t\tpress 1 or 2: ";
      cout << "enter choice";
      cin >> ch;
      if (ch == 1)
	{
	  teaching *tptr;
	  tptr = &i[j];
	  
	  person *ptr= tptr;  
  	  ptr->accept();
	  tptr->accept();
	}
      else if (ch == 2)
      {
	nonteaching *nptr;
	  nptr = &i[j];
	  person *ptr= nptr;  
	  ptr->accept();
	  nptr->accept();
	  }
  }
  
  
  cout << "hiiiii\n";
  for(j=0;j<n;j++)
  {
    i[j].display();
  }
  */
  
  /*
  nonteaching *nptr;
  nptr = &i;
  nptr->accept();

  person *ptr= nptr;  
  ptr->accept();
  */
  
  
  


  person **ptr;
  instructor *i;
  int m, n, ch;
  cout << "\n\t\tHow many instructors : ";
  cin >> n;

  ptr = new person* [n];
  i = new instructor[n];

  for (int j = 0; j < n; j++)
    {
      cout << "\n\t\t accessing data for inst" << j + 1;
      
	cout << "\n\t\tteching or non  \n\t\tpress 1 or 2: ";
      cout << "enter choice";
      cin >> ch;
      if (ch == 1)
	ptr[j] = new teaching;
     else 
        ptr[j] = new nonteaching;
	
	
      ptr[j]->accept ();// calls 
      //appripriate fun
      i[j].accept();
    }

  for (int j = 0; j < n; j++)
    {
      cout << endl;
      ptr[j]->display ();
      i[j].display ();
    }
}
