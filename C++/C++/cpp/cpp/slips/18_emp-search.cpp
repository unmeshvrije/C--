#include<iostream>
using namespace std;

class emp
{
int code;
char name[20],des[20];
public:
void getemp();
void putemp();
int fetchcode();
};
int emp::fetchcode()
{
return code;
}
void emp::getemp()
{
cout<<"\n\t\tEnter the code : ";cin>>code;
cout<<"\n\t\tEnter the name : ";cin>>name;
cout<<"\n\t\tEnter the designation : ";cin>>des;
}
void emp::putemp()
{
cout<<"\n"<<code<<"\t"<<name<<"\t"<<des;
}

class emp_acc :public emp
{
int accno;
char date[20];
public:
void getacc();
void putacc();
};
void emp_acc::getacc()
{
cout<<"\n\t\tEnter account number : ";cin>>accno;
cout<<"\n\t\tEnter date of joining : ";cin>>date;
}
void emp_acc::putacc()
{
cout<<"\t"<<accno<<"\t"<<date;
}

class emp_sal :public emp_acc
{
int bp,e,d;
public:
void getsal();
void putsal();
};
void emp_sal::getsal()
{
cout<<"\n\t\tEnter basic pay : ";cin>>bp;
cout<<"\n\t\tEnter earnings : ";cin>>e;
cout<<"\n\t\tEnter deductions : ";cin>>d;
}
void emp_sal::putsal()
{
cout<<"\t"<< bp <<"\t"<< e << "\t" <<d <<"\t"<< bp+e-d;
}

int menu()
{
int ch;
cout<<"\n\t\t0)Exit";
cout<<"\n\t\t1)Build master table";
cout<<"\n\t\t2)Search the record ";
cout<<"\n\t\t3)Display";
cout<<"\n\t\tEnter the choice : ";
cin>>ch;
return ch;
}

main()
{
int ch,n,data,flag=0;
emp_sal e[10];
while((ch=menu())!=0)
{

switch(ch)
{
case 1:
cout<<"\n\t\tHow many records : ";
cin>>n;
for(int i=0;i<n;i++)
{
e[i].getemp();       //as public inheritance is used we can call all the functions
e[i].getacc(); 	     //   here only using object of the class emp_sal	
e[i].getsal();	    //  otherwise    we would use  private inheritance
}
break;

case 2:
cout<<"\n\t\tEnter code of emp whose record is to be searched :";
cin>>data;
flag=0;
for(int i=0;i<n;i++)
{
if(e[i].fetchcode() == data)
{
e[i].putemp();
e[i].putacc();
e[i].putsal();
flag=1;
}
}
cout<<flag;
getchar();
if(flag==0)
cout<<"\n\t\tRecord not found";
getchar();
break;

case 3:
cout<<"\nCode\tName\tDesig\tA/C_No\tJoin-date\tBAsic_pay\tEarning\tDeduction\tTotal";
for(int i=0;i<n;i++)
{
e[i].putemp();
e[i].putacc();
e[i].putsal();
}
break;


}

}


}
