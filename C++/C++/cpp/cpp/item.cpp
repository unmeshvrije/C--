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
cout<<"\t"<<item_no<<"\t"<<name<<"\t"<<qty<<"\t"<<price;
}
}
int main()
{
item i;
i.getitem();
i.putitem();

return 0;
}
