#include<iostream>
#include<string.h>
using namespace std;

class sstring
{
  struct srep
  {
    char *s;
    int n;
      srep ()
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
  if (p->n > 1)		//disconnect self
    {
      p->n--;
      p = new srep;
    }
  else			//free old string
    delete[]p->s;

  p->s = new char[strlen (s) + 1];
  strcpy (p->s, s);
  return *this;
}

sstring & sstring::operator= (const sstring & x)
{
  ((x.p)->n)++;		//protect against st=st
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


     int
     main ()
{
sstring s1,s2;
s1="Unmesh";
cout<< s1;

cin >> s2;
cout<<"\n"<<s2;

getchar();
sstring s3("Pranav");
cout<<"\n"<<s3;

sstring s4=s3,s5;
cout<<"\n"<<s4;

s5=s1;
cout<<"\n"<<s5;

sstring s6[5];//array of strings 

for(int i=0;i<5;i++)
cin>>s6[i];

cout<<"\n\t\tArray of strings";
for(int i=0;i<5;i++)
cout<<"\n"<<s6[i];

sstring s7=s1;
int t = (s7=="unmesh");
if(t==0)
cout << "\n\t\tMatching";

t=(s7!=s3);
if(t!=0)
cout<<"\n\t\tNot matching";

  return 0;
}
