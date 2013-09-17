#include<iostream>
using namespace std;

class Number
{
    int value;
    public :
    
    Number() //default constructor
    {
      //any initialization(s) along
      // with supportive information
      
       cout<< endl <<"Object Created";
       value = 0;
       cout << endl <<" Initial value = 0";
    }
    
    ~Number()
    {
      cout <<endl<< "Object Destroyed";
    }
    
    Number(int value)
    {
     cout<< endl <<"Object Created";
    	this->value = value;
    }
    
    void getData()
    {
      cout<<endl <<"Enter value : ";
      cin >> value;
    }
    void putData()
    {
      cout<< endl <<value;
    }
    
};


main()
{
    Number n1,n5;
   n1.getData();
   cout<< "\n n1 = ";
   n1.putData();
   
   //n5.Number(5);// Not Allowed
   
   n1.~Number();  //called Explicitly.
   
   Number n2(2);
   cout<< "\n n2 = ";
   n2.putData();
   
   Number n3(3);
   cout<< "\n n3 = ";
   n3.putData();
   
   n2.~Number();
   n3.~Number();
   
   
   Number n4(4);
   cout<< "\n n4 = ";
   n4.putData();
   n4.~Number();
   
}
