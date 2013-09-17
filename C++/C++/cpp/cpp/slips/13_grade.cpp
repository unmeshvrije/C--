#include<iostream>
using namespace std;

class student
{
	int roll;
	char name[20],cl[10];
public:
void getst();
void putst();
};

void student::getst()
{
cout<<"\n\t\tEnter roll";cin>>roll;
cout<<"\n\t\tEnter name";cin>>name;
cout<<"\n\t\tEnter class";cin>>cl;
}

void student::putst()
{
cout<<"\n"<<roll<<"\t"<<name<<"\t"<<cl;
}

class marks
{
int m[3];
public:
void getm();
void putm();
int fetchm();
};

void marks::getm()
{
cout<<"\n\t\tEnter marks in 3 sub: ";
cin>>m[0]>>m[1]>>m[2];
}

void marks::putm()
{
cout<<"\t"<<m[0]<<"\t"<<m[1]<<"\t"<<m[2];
}
int marks::fetchm()
{
int sum=m[0]+m[1]+m[2];
return sum;
}

class grade :public student,public marks
{
	float p;
	char g;
public:
	float getp();
	void cal();
	void putg();
};

float grade::getp()
{
return p;
}

void grade::putg()
{
cout<<"\t"<< p <<"\t"<<g;
}

void grade::cal()
{
int t = fetchm();
//cout<<"\n\t\tt="<<t;
p= (float)t/3;
if(p >=75 )
g='A';
else if(p>=60 && p<75)
g='B';
else if(p>=50 && p<60)
g='C';
else
g='D';
getchar();
}



main()
{
int n,ch;
grade *g;
cout<<"\n\t\tHow many students : ";
cin>>n;
g=new grade[n];


for(int i=0;i<n;i++)
{
g[i].getst();       //as grade is " publically"inheriting student & marks we can call like this
g[i].getm();
g[i].cal();
}

for(int i=0;i<n;i++)
{
g[i].putst();//st udents
g[i].putm(); // m arks
g[i].putg(); // g rade
}

for(int i=0;i<n;i++)
{
for(int j=i+1;j<n;j++)
{
if( g[i].getp() <= g[j].getp())
{
grade temp;
temp=g[i];
g[i]=g[j];
g[j]=temp;
}
}
}

cout<<"\n\n\t\tAfter sorting .......\n";

for(int i=0;i<n;i++)
{
g[i].putst();
g[i].putm();
g[i].putg();
}

}//main
