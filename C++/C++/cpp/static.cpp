/*
 1)A static function can have access to only
 other static variables or functions 
 declared in SAME CLASS.
 
 2)A static member function can be called 
 using the same class name.
 
 Syntax:
 Class_Name:: function_name; 
 
 
*/





#include<iostream>
using namespace std;

class test
{
	int code;
	static int count;
public:	
	void setCode()
	{
	   code = ++count;
	}
	
	void display()
	{
	  cout << endl<<"Display count = "<< count;
	}
	
	void showCode()
	{
	  cout<< endl<<"object code = " << code ;
	  
	}
	static void showCount()
	{
	  cout <<endl<< "Count : " << count;
//	  cout << " code =" <<code;
	}
};

int test::count; //declaration of static member

main()
{
	test t1,t2;
	
	t1.setCode(); // t1.code =1
	t1.display();

	t2.setCode();// t2.code = 2
	t2.display();
	//test::display();
	
	test::showCount();//accesses static fun
	t1.showCount();
	/*
	test t3;
	
	t3.display();
	
	t3.setCode();
	test::showCount();//accesses static fun
	
	
	t1.display();
	
	t1.showCode();
	t2.showCode();
	t3.showCode();*/
	
	return 0;
}
