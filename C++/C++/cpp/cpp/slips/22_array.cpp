#include<iostream>
using namespace std;

class Array
{
	int *a;
	int n;
public:
void accept();
void display();
void operator+(Array &);
};

void Array::operator + (Array &temp)
{  // this: a1		// a2
	cout<<endl;
	//if first array is smaller than
	// second in length
	if( this->n <= temp.n)
	{
	for(int i=0; i<n ;i++)
	  cout<< "\t"<<a[i] + temp.a[i];
	for(int i=n;i<temp.n;i++)
	cout<<"\t"<<temp.a[i];
	}
	else 
	{
	for(int i=0; i<temp.n ;i++)
	  cout<<"\t"<< a[i] + temp.a[i];
	for(int i=temp.n;i<n;i++)
	   cout<< "\t"<<a[i];
	}
}
void Array::accept()
{
	cout<<"\n\t\tEnter size : ";
	cin>>this->n;
	a=new int[n];//like cosntructor of int
	for(int i=0;i<n;i++)
	{
	  cout <<"enter element ("<< i+1<<") : ";
	  cin>> a[i];
	}
}

void Array::display()
{
	for(int i=0;i<n;i++)
	cout<<"\t"<<a[i];
}
main()
{
	Array a1,a2;
	a1.accept();
	a1.display();
	a2.accept();
	a2.display();
	a1+a2;
	//a1.operator+(a2);
}
