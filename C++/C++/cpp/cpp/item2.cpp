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
void putitem();

};
void item::getitem()
{
cout<<"\n\t\tenter item info :\n";
cin>>item_no>>name>>qty>>price;
ofstream write("item.txt",ios::app);
write<<"\n"<<item_no <<"\t" <<name <<"\t" <<qty  <<"\t"  <<price;
}

void item::putitem()
{
ifstream read("item.txt");
while(!read.eof())
{
read >>item_no>>name>>qty>>price;
cout<<"\n"<<item_no<<"\t"<<name<<"\t"<<qty<<"\t"<<price;

//read >>getline(read);
//cout<<getline(read);
}
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
while((ch=menu())!=0)
{
switch(ch)
{
case 1:

i.getitem();
break;


case 2:

i.putitem();
break;

default:break;


}//swi
}//while


return 0;
}//main

