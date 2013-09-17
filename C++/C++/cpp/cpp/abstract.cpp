#include<iostream>
using namespace std;

class person
{
	int ssn;
	public:
	virtual ~person()=0;
	person();
};

person::person()
{
	cout<<endl<<"person created";
}

person :: ~person()
{
	cout<<endl<<"person deleted";
}


class student : public person
{
	public:
	student()
	{
		cout<<endl<<"student created";
	}
	
	~student()
	{
		cout<<endl<<"student deleted";
	}
};

int main()
{
	//person p;
	student *s = new student;
	delete s;
	return 0;
}
