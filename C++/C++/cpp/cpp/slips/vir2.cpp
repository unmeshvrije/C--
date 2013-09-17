#include<iostream>
using namespace std;

class person
{
protected:
int id;
char name[20];
public:
virtual void accept()
{
}
virtual void display(){}
};

class teaching: public person
{
protected:
char sub[20];
public:
void accept();
void display();
};

void teaching :: accept()
{
cout<<"\n\t\tEnter id: ";cin>>id;
cout<<"\n\t\tEnter name: ";cin>>name;
cout<<"\n\t\tEnter sub: ";cin>>sub;
}
void teaching :: display()
{
cout<<"\n"<< id <<"\t"<<name<<"\t"<<sub<< "(teaching)";
}

class nonteaching: public person
{
protected:
char dept[20];
public:
void accept();
void display();

};
void nonteaching :: accept()
{
cout<<"\n\t\tEnter id: ";cin>>id;
cout<<"\n\t\tEnter name: ";cin>>name;
cout<<"\n\t\tEnter dept: ";cin>>dept;
}
void nonteaching :: display()
{
cout<<"\n"<< id <<"\t"<<name<<"\t"<< dept <<"(nonteaching)";
}

class instructor : public teaching , public nonteaching
{
person *ptr;
public:
instructor();
~instructor();
};

instructor::instructor()
{
int ch;
//person *ptr;
cout<<"\n\t\tTeaching or nonteaching : ";
cin >> ch;
if(ch==1)
{
ptr=new teaching;
ptr->accept();
}
else if(ch==2)
{
ptr =new nonteaching;
ptr->accept();
}
};

instructor :: ~instructor()
{
cout<<"Destroying........";
ptr->display();
}

main()
{
//person **ptr;
instructor *i;
int m,n,ch;
cout<<"\n\t\tHow many instructors : ";
cin>>n;

//ptr=new person*[n];
i = new instructor[n];

delete (i+0);
//delete i[];
/*for(int j=0;j<n;j++)
{
delete (i+j);
}*/

/*for(int j=0;j<n;j++)
{
cout<<"\n\t\t accessing data for inst"<<j+1;
cout<<"\n\t\tteching or non  \n\t\tpress 1 or 2: ";
cout<<"enter choice";
cin>>ch;
if(ch==1)
ptr[j]=new teaching;
else if(ch==2)
ptr[j]=new nonteaching;

ptr[j]->accept();
i[j].accept();
}

for(int j=0;j<n;j++)
{
cout<<endl;
ptr[j]->display();
i[j].display();
}*/
//for(int j=0;j<n;j++)
//delete (i+j);
}
