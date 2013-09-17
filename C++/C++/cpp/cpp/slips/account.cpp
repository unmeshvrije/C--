#include<iostream>
using namespace std;

class acc
{
int ac_no;
char name[20];
public:
void getacc();
void putacc();
int fetchac();
};

int acc::fetchac()
{
return ac_no;
}
void acc::getacc()
{
cout<<"\n\t\tEnter A/C no : ";cin>>ac_no;
cout<<"\n\t\tEnter customer name  : ";cin>>name;
}
void acc::putacc()
{
cout<<"\n"<<ac_no<<"\t"<<name;
}

class sav :public acc
{
int bal;
float min_am;
public:
void getsav(int);
void putsav();
void deposit(int);
void with(int);
};

void sav::deposit(int data)
{
cout<<"\n\ndata :"<<data;
bal = bal + data;
cout<<"\n\n\t\tYour balance has become : "<< bal;
getchar();
putacc();
getchar();
putsav();
getchar();
}
void sav::with(int data)
{
if(bal-data < min_am)
cout<<"\n\t\tCan't withdraw so much money .";
else
{bal-=data;
cout<<"\n\n\t\tYour balance has become : "<< bal;}
getchar();
putacc();
getchar();
putsav();

}

void sav::getsav(int a1)
{
cout<<"\n\t\tEnter balance: ";cin>>bal;
min_am=a1;
}
void sav::putsav()
{
cout<<"\t"<<bal<<"\t"<<min_am;
}

class cur :public acc
{
int bal;
float min_am;
public:
void getcur(int);
void putcur();
};
void cur::getcur(int a2)
{
cout<<"\n\t\tEnter balance: ";cin>>bal;
min_am=a2;
}
void cur::putcur()
{
cout<<"\t"<<bal<<"\t"<<min_am;
}

int menu2()
{
int ch;
cout<<"\n\t\t1)Create Account";
cout<<"\n\t\t2)Deposit";
cout<<"\n\t\t3)Withdrawal";
cout<<"\n\t\tENter choice : ";
cin>>ch;
return ch;
}
int menu()
{
int ch;
cout<<"\n\t\t1)Saving Account";
cout<<"\n\t\t2)Current Account";
cout<<"\n\t\t3)Exit";
cout<<"\n\t\tEnter choice";
cin>>ch;
return ch;
}

main()
{
int ch,i=0,ch2,j=0,temp,a1,a2,n,no;
sav s[10];
cur c[10];

cout<<"\n\t\tEnter minimum amount for Saving Account : ";
cin>>a1;
cout<<"\n\t\tEnter minimum amount for Current Account : ";
cin>>a2;

 while((ch=menu())!=3)
{

switch(ch)
{

case 1:

while((ch2=menu2())!=4)
{
switch(ch2)
{
case 1:
cout<<"\n\t\ti="<<i;
s[i].getacc();
s[i].getsav(a1);  //passing minimum amount to saving account
s[i].putacc();
s[i].putsav();
i++;
cout<<"\n\t\ti="<<i;
break;

case 2:
cout<<"\n\t\tEnter account number :";
cin>>no;
cout<<"\n\t\tEnter amount to be deposited : ";
cin>>temp;
for(int j=0;j<=i;j++)
{
if(s[j].fetchac() == no)
{s[j].deposit(temp);
break;}
}

break;
case 3:
cout<<"\n\t\tEnter account number :";
cin>>no;
cout<<"\n\t\tEnter amount to be withdrawn : ";
cin>>temp;
for(int j=0; j<=i;j++)
{
if(s[j].fetchac() == no)
{s[j].with(temp);
break;}
}
break;
default :break;
}//switch

}//while

break;

case 2:
while((ch2=menu2())!=4)
{
switch(ch2)
{
case 1:
c[j].getacc();
c[j].getcur(a2);
c[j].putacc();
c[j].putcur();
j++;
break;

case 2:
break;

case 3:
break;
default : break;
}
}
break;


default : break;

}
}//while
}
