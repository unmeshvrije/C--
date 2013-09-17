#include<iostream>
#include<ios>
#include<fstream>
using namespace std;

class item
{
int item_no,qty;
char name[20];
float price;

public:
void getitem();
int putitem(int);

};
void item::getitem()
{
cout<<"\n\t\tenter item info :\n";
cin>>item_no>>name>>qty>>price;
ofstream write("item.txt",ios::app);
write<<"\n"<<item_no <<"\t" <<name <<"\t" <<qty  <<"\t"  <<price;
write.close();
}

int item::putitem(int n)
{
int cnt1=0,cnt2=0,flag_end=0,temp,t2,temp2;
ifstream read("item.txt");
read.seekg(ios::end);
temp=read.tellg();
cout<<"\nend="<<temp;
read.seekg(ios::beg);

cout<<"\n n="<< n;

while(!read.eof() && (++cnt1 <= n))
{
read >>item_no>>name>>qty>>price;
if(read.eof() && cnt1==n)
{
flag_end=1;
read.seekg(-12,ios::cur);
break;
}
//if(n==item_no)
// t2=read.tellg();
}
/*temp2=read.tellg();
cout<<"\n"<<temp2;*/
if(!read.eof())
{cout<<"\n"<<item_no<<"\t"<<name<<"\t"<<qty<<"\t"<<price;
cnt2++;}
/*if(t2 ==temp)
{cout<<"\n"<<item_no<<"\t"<<name<<"\t"<<qty<<"\t"<<price;
cnt++;*/
if(flag_end==1)
{
cout<<"\n"<<item_no<<"\t"<<name<<"\t"<<qty<<"\t"<<price;
cnt2++;
}

/*else
{
cout<<"\n\t\tThe record does not exist.";
continue;
}*/

read.close();
return cnt2;
}
int menu()
{
int ch;
cout<<"\n\t\t0)Exit";
cout<<"\n\t\t1)Add a record";
cout<<"\n\t\t2)Retrieve nth record";
cout<<"\n\t\tEnter the choice";
cin>>ch;
return ch;
}
int main()
{
int ch,j,k;

item i;
while( (ch=menu()) !=0)
{
switch(ch)
{
case 1:

i.getitem();
break;


case 2:
int n,ans;
cout<<"\n\t\tEnter n ";
do
cin>>n;
while(n<=0);

ans=i.putitem(n);

if(ans==0)
cout<<"The record does not exist";

break;

default:break;
}//swi
}//while
return 0;
}//main
