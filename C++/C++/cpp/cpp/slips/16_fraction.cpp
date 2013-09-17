#include<iostream>
using namespace std;
class fraction
{
long num,dem;

public:
fraction(long,long);
friend istream& operator >>(istream &in,fraction& );
friend ostream& operator <<(ostream & out,fraction& );
fraction& fraction::operator ++(int);
fraction& fraction::operator ++();
};

fraction::fraction(long n=0,long d=1)
{
num=n;
dem=d;
}

istream& operator >>(istream &in,fraction &f1)
{
cout<<"\n enter the numerator and denominator";
in>>f1.num>>f1.dem;
return in;
}

ostream& operator <<(ostream & out,fraction &f1)
{
out<<f1.num<<"/"<<f1.dem;
return out;
}

fraction& fraction::operator ++(int)
{
fraction temp;
temp=*this;
num++;
dem++;
return temp;
}
fraction& fraction::operator ++()
{
num++;
dem++;
return *this;
}

main()
{
fraction f1,f2;
cin>>f1;
cout<<f1;
cout<<"\n result of overloading postincrement operator";
f2=f1++;
cout<<f2;
cout<<"\n result of overloading preincrement operator";
++f1;
cout<<f1;
}
