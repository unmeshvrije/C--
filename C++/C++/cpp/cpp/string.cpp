#include<iostream>
#include<string.h>
using namespace std;

class sstring
{
  struct srep
  {
    char *s;
    int n;
      srep () // constructor of structure
    {
      n = 1;
    }
  };
  srep *p;

public:
  sstring (const char *);	//string x="bc";
  sstring ();
  sstring (const sstring &);
  sstring & operator= (const char *);
  sstring & operator= (const sstring &);
  ~sstring ();
  char &operator [] (int i);
  const char &operator [] (int i) const;

  friend ostream & operator<< (ostream &, const sstring &);
  friend istream & operator>> (istream &, sstring &);

  friend int operator== (const sstring & x, const char *s)
  {
    return strcmp (x.p->s, s) == 0;
  }

  friend int operator== (const sstring & x, const sstring & y)
  {
    return strcmp (x.p->s, y.p->s) == 0;
  }

  friend int operator!= (const sstring & x, const char *s)
  {
    return strcmp (x.p->s, s) != 0;
  }

  friend int operator!= (const sstring & x, const sstring & y)
  {
    return strcmp (x.p->s, y.p->s) != 0;
  }

};				//end of class

sstring::sstring ()
{
  p = new srep;
  p->s = 0;
}

sstring::sstring (const sstring & x)     
{

  x.p->n++;
  p = x.p;
}

sstring::sstring (const char *s)
{
  p = new srep;
  p->s = new char[strlen (s) + 1];
  strcpy (p->s, s);
}

sstring::~sstring ()
{
  if (--p->n == 0)
    {
      delete[]p->s;
      delete p;
    }
}

sstring & sstring::operator= (const char *s)
{
  if (p->n > 1)			//disconnect self
    {
      p->n--;
      p = new srep;
    }
  else				//free old string
    delete[]p->s;

  p->s = new char[strlen (s) + 1];
  strcpy (p->s, s);
  return *this;
}

sstring & sstring::operator= (const sstring & x)
{
cout<<"hiiiii";
  ((x.p)->n)++;			//protect against st=st
  if (--p->n == 0)
    {
      delete[]p->s;
      delete p;
    }
  p = x.p;
  return *this;
}

ostream & operator<< (ostream & s, const sstring & x)
{
  return s << x.p->s << "[" << x.p->n << "]\n";
}

istream & operator>> (istream & s, sstring & x)
{
  char
    buf[256];
  s >> buf;
  x = buf;
  cout << "\necho:" << x << "\n";
  return s;
}

char &
sstring::operator[] (int i)
{
  if (i < 0 || strlen (p->s) < i)
    cout << "index out of range";
  if (p->n > 1)
    {
//clone to maintain value semantics
      srep *np = new srep;
      np->s = new char[strlen (p->s) + 1];
      (p->n)--;
      p = np;
    }
  return p->s[i];
}

const char &
sstring::operator[] (int i)
     const
     {
       if (i < 0 || strlen (p->s) < i)
	 cout <<
	   "index out of range";
       return
	 p->
	 s[i];
     }


int main ()
{
  sstring x[10];
  int    n;
  cout << "\n\t\there we go......\n";

  for (n = 0; cin >> x[n]; n++)
    {
      if (n == 9)
	{
	  cout << "too many strings";
	  //return 9;
	  break;
	}			//if
      sstring y;
      cout << (y = x[n]);
      if (y == "done")
	break;
    }				//for

  cout << "\n\t\there we go back";
  for (int i = n ; 0 <= i; i--)
    cout << x[i];

/*sstring s1,s2;
s1="unmesh";
cout<< s1;
getchar();

cin>>s2;
cout<<"\n"<<s2;*/


sstring s1="unmesh";

sstring s2;

s2 =s1;
cout << s1;
cout<< s2;



  return 0;
}
