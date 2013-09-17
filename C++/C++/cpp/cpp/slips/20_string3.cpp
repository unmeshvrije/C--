#include<iostream>
#include<string.h> 
using namespace std;
class Cstring
{
char *ptr;
int len;
public:
Cstring(char *);
Cstring();
Cstring(Cstring &);
void display();
Cstring & operator+(Cstring &);
void operator=(Cstring& );
};

void Cstring :: operator=(Cstring& s)
{
///if(ptr)
//delete ptr;
len= s.len;
ptr=new char [len + 1];
strcpy(ptr,s.ptr);
}

Cstring& Cstring::operator+(Cstring & s2)
{
Cstring temp;
temp.len = len + s2.len;
temp.ptr= new char [temp.len + 1];
temp.ptr= (strcat(this->ptr,s2.ptr));
return temp;
}

Cstring::Cstring(){}  //default constructor for declaration Cstring s3;

void Cstring::display()
{
cout<<"\n\t\t"<<ptr;
}

Cstring::Cstring(Cstring &s)  //s1=s2  situation  --> s1 is implicit & s2 is passed
{
this->len=s.len;                 //s1 contains "this"
this->ptr=new char [s.len+1];
strcpy(this->ptr,s.ptr);
}

Cstring::Cstring(char *str)
{
int len=strlen(str);
ptr=new char[len+1];
strcpy(ptr,str);
}
main()
{
Cstring s1("unmesh"),s2("sagar"); // both  will invoke "Cstring(char *)" constructor
Cstring s3,s4;			// will invoke default constructor
s1.display();
s2.display();
s3=s1;   //calls copy constructor here
s3.display();
s4=s1+s2;//this will expand to  s4=s1.function(s2)
s4.display();
}//main
