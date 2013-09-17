#include<iostream>
using namespace std;


class Student{

	int roll;
	int age;
	char name[20];

	public:
		static int count;
	
	Student() //constructor
	{
	
	}
	void getdata()
	{	
	  cout << "Enter roll : ";
	  cin >> roll;
	  count ++;	
	}
	void putdata()
	{ 
	 cout <<endl << " roll = " <<roll;
	 cout <<endl << "count =" << count;
	}
};

int Student :: count;

main()
{
 
 Student ram;  // like int i;
 ram.getdata(); 
 ram.putdata(); 
 Student raj;
 raj.getdata(); 
 raj.putdata(); 
 Student raju;
 raju.getdata(); 
 raju.putdata(); 

 
 Student *ptr; // like int *ptr
 // dynamic memory allocation
 
 ptr = new Student(); // like ptr =new int();
 
 cout << "count = "  << Student::count;
}
