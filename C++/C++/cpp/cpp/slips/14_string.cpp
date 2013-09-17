#include<iostream>
#include<ctype.h>
using namespace std;
class String

{
char *ptr;
int len;
public:
String();
friend istream &operator >>(istream &in,String & s);
friend ostream &operator <<(ostream &out,String & s);
int operator==(String s2);
void operator-();
};

void String::operator-()
{
for(int i=0;ptr[i]!='\0';i++)
{
if( (ptr[i] < 90)&&(ptr[i]>65))
ptr[i]+=32;
else if( (ptr[i] < 122)&&(ptr[i]>97))
ptr[i]-=32;
}

}

int String::operator==(String s2)
{
int i;
for(i=0;s2.ptr[i]!='\0';i++ )
{
if(this->ptr[i]!=s2.ptr[i])
return 0;
}
return 1;
}


istream &operator >>(istream &in,String & s)
{
cout<<"\n\t\tEnter the string : ";
in >> s.ptr;
return in;
}
ostream &operator <<(ostream &out,String & s)
{
out << s.ptr;
return out;
}

String::String()
{
cout<<"\n\t\tEnter the length: ";
cin>>len;
ptr=new char[len+1];
ptr[len+1]='\0';
}

int main()
{
String s1;
cin >> s1;// cin will be treated as first parameter to the overloaded fun
cout<<"\n\t\tThe string you have entered is : ";
cout<<s1;
String s2;
cin >> s2;// cin will be treated as first parameter to the overloaded fun
cout<<"\n\t\tThe string you have entered is : ";
cout<<s2;

int c=(s1==s2);
if(c==1)
cout<<"\n\n\t\t"<<s1<<"and"<<s2<<"are"<<"Matched";
else
cout<<"\n\n\t\tNot matched";

-s2;
cout<<"\n\t\tAfter Case conversion"<<s2;



return  0;
}
