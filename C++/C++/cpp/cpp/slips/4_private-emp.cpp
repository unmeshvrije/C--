#include<iostream>
using namespace std;

class person
{
	char name[20],add[20];
	long int phno;
public:
	void getperson();
	void putperson();
};
void person::getperson()
{
cout<<"\n\t\tEnter name: ";cin>>name;
cout<<"\n\t\tEnter Address: ";cin>>add;
cout<<"\n\t\tEnter phone number: ";cin>>phno;
}
void person::putperson()
{
  cout<<"\n"<<name<<"\t"<<add<<"\t"<<phno;
}

class emp :private person //person's public will come in emp's  private
{
int e_id;
char e_name[20];
//getPerson();
//putPerson();
public:
void gete();
void pute();
};
void emp::gete()
{
getperson();
cout<<"\n\t\tEnter emp_id : ";cin>>e_id;
cout<<"\n\t\tEnter emp_name : ";cin>>e_name;
}
void emp::pute()
{
putperson();
cout<<"\t"<<e_id<<"\t"<<e_name;
}

class manager :private emp
{
	private:
	  char des[20],dept[20];
	  int sal;
	  //gete()
	  //pute()
	public:
	  void getm();
	  void putm();
	  int getsal();
};
int manager::getsal()
{
return sal;
}
void manager::getm()
{
gete();
cout<<"\n\t\tEnter designation : "; cin >> des;
cout<<"\n\t\tEnter department : "; cin >> dept;
cout<<"\n\t\tEnter salary :";cin>>sal;
}
void manager::putm()
{
pute();
cout<<"\t"<<des<<"\t"<<dept<<"\t"<<sal;
}

int menu()
{
int ch;
cout<<"\n\t0)Exit";
cout<<"\n\t1)Accept details of n managers ";
cout<<"\n\t2)Display manager having highest salary   ";
cout<<"\n\tEnter choice : ";
cin>>ch;
return ch;
}
main()
{
int ch,n,max=0;
manager m[20];
	while((ch=menu())!=0)
	{
		switch(ch)
		{
		case 1:
		cout <<"\n\t\tHow many managers : ";cin>>n;
		for(int i=0; i<n;i++)
		{
		cout <<endl <<"Enter info  for person ["<< i+1 <<"] : ";
		m[i].getm();
		//m[i].getperson();
		}
		for(int i=0; i<n;i++)
		m[i].putm();
		break;
		case 2:
		for(int i=0;i<n;i++)	
		{
		if((m[i].getsal()) > max)  //storing the max salary in "max"
		max=m[i].getsal();
		}
for(int i=0;i<n;i++)         //match the sal of each record with "max"
{
if((m[i].getsal() ) ==max)   //and display that record.
m[i].putm();
}
        break;
		default :cout<<"Invalid Choice.";break;
		}
	}
}//main
