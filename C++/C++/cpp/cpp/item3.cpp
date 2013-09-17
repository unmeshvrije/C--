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
int cnt=0;
ifstream read("item.txt");
cout<<"\n n="<< n;
while(!read.eof())
{
read >>item_no>>name>>qty>>price;
if(n==item_no)
{cout<<"\n"<<item_no<<"\t"<<name<<"\t"<<qty<<"\t"<<price;
cnt++;
}

/*else
{
cout<<"\n\t\tThe record does not exist.";
continue;
}*/
}
read.close();
return cnt;
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
