#include<iostream>
using namespace std;

class person
{
char name[20];
char add[25];
int phno;

public:

void getper()
{
cout <<"\n\t\tEnter person details : ";
cin >>name>>add>>phno;
}

void putper()
{
cout<<"\n\t"<<name<<"\t"<<add<<"\t"<<phno;
}

};

class emp :private person
{
int eno;
char ename[20];
/*virtually here:
member functions:getper(),putper()
*/
public:
void getemp(person& p)
{
p.getper();
cout <<"\n\t\tEnter employee number : ";
cin>> eno;
//strcpy(ename,p.getname());
}
void putemp(person& p)
{
p.putper();
cout<<"\t"<<eno;
}

void getperson()
{

}


};//emp class

/*class manager:private emp
{
private:
char desig[20],dept[20];
long int sal;

getemp
putemp
getperson

public:
void getman(emp &e)
{
e.getperson();
e.getemp();
cout<<"\n\t\tEnter manager's details: ";
cin>>desig>>dept>>sal;
}
void putman(emp &e)
{
//p.putper();
e.putemp();
cout<<"\t"<<desig<<"\t"<< dept<<"\t"<<sal;
}




};*/


int main()
{
person p;
//p1.getper();
//p1.putper();
emp e;
e.getemp(p);
e.putemp(p);

//manager m;
//m.getman(e);
//m.putman(e);

return 0;
}
