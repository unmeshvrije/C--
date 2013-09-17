#include<iostream>
using namespace std;
class fraction
{
int num,dem;
public:
fraction();
int operator<(fraction&);
friend ostream& operator <<(ostream& out,fraction&);
friend istream& operator>>(istream& in,fraction&);
};


int fraction::operator<(fraction &f2)
{
float temp1=(float)this->num / (float)this->dem;
float temp2=(float)f2.num / (float)f2.dem;
if(temp1<temp2)
return 1;
else if(temp1==temp2)
return 2;
return 0;
}


fraction::fraction()
{
num=0;dem=1;
}

istream& operator>>(istream& in,fraction &f1)
{
cout<<"\n enter the numerator and denominator";
in>>f1.num>>f1.dem;
return in;
}

ostream& operator <<(ostream& out,fraction &f1)
{
cout<<(float)f1.num/(float)f1.dem;
return out;
}


main()
{
fraction f1;
fraction *ptr;
cin>>f1;
cout<<f1;
fraction f2;
cin>>f2;
cout<<f2;

int ans=(f1<f2);
if(ans==1)
cout<<"\n\t\t"<<f1<<"<"<<f2;
else if(ans ==2)
cout<<"\n\t\t"<<f1<<"="<<f2;
else
cout<<"\n\t\t"<<f1<<">"<<f2;

int n ;
cout<<"\n\t\tEnter n : ";
cin>>n;
ptr=new fraction[n];

for(int i=0;i<n;i++)
cin >>ptr[i];

cout<<"\n\t\tFractions you have entered are:";
for(int i=0;i<n;i++)
cout <<"\n"<<ptr[i];

for(int i=0;i<n;i++)
{
for(int j=i+1;j<n;j++)
{
if( (ptr[i]<ptr[j]) ==0 )
{
fraction temp;
temp=ptr[i];
ptr[i]=ptr[j];
ptr[j]=temp;
}
}
}

cout<<"\n\n\t\tFractions after sorting :\n\n";
for(int i=0;i<n;i++)
cout <<"\n"<<ptr[i];




}//main
