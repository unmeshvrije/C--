#include<iostream>
using namespace std;

class person
{
   // data members
   
  char name[30];
  int age;
  //void read(); //private method does exist
  
  public:
 void getdata(void); //method declaration
void display(void)//method declaration and definition
{
cout <<endl <<"\t"<< name << endl << age <<endl << pid; // endp is \n
}
  private:
   int pid;
   public: void setdata(char[],int,int);
};

inline void person::getdata(void)
{
  cout <<"Enter name : ";
  cin>> name;
  cout <<"Enter age : ";
  cin>> age;
  cout <<"Enter pid : ";
  cin>> pid;
}

void person::setdata(char n[],int a,int p)
{
   strcpy(name,n);
   age = a;
   pid = p;
}
main()
{

   person raj,p;
   //p.age = 10;
   
   raj.setdata("raj",20,101);
   p.getdata();
   raj.display();
   p.display();
   return 0;
}
