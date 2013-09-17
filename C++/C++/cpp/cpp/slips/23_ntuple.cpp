#include<iostream>
using namespace std;

class ntuple
{
int *arr,max,min,sz;
public:

ntuple(int);
~ntuple();
void display();
void read();
int product(ntuple);
};

int ntuple::product(ntuple t)
{
//this , t
int sum=0;
for(int i=0;i<t.sz;i++)
 sum += (this->arr[i] * t.arr[i]);
 
return sum;
}

ntuple::ntuple(int s=3)
{
	max=0;
	min=32767;
	sz=s;
	arr=new int[sz];
}
ntuple::~ntuple()
{
cout<<"\n\t\tTuple is destroyed .";
}
void ntuple::read()
{
	for(int i=0 ; i < sz ; i++)
	{
	cout <<"\n\t\tEnter elements (" << i+1 << ") :";
	cin >>arr[i];
	}
	for(int i=0 ; i<sz ; i++)
	{
		if(arr[i] > max)
		max=arr[i];
		else if(arr[i] < min)
		min=arr[i];
	}
}

void ntuple::display()
{
cout<<"(";
for(int i=0;i<sz;i++)
{
cout<<arr[i]<<",";
}
cout<<")";
//cout<<"\n\t\tmax="<<max;
//cout<<"\n\t\tmin="<<min;
}

main()
{
ntuple *t;
int n;
cout<<"\n\t\tHow many tuples : ";
cin>>n;
t=new ntuple[n];

for(int i=0; i<n ; i++)
{
cout<<"\n\n\t\tAccessing the data for tuple "<< i+1<<".....";
t[i].read();
}

for(int i=0; i<n ; i++)
{
cout<<"Tuple"<<i+1<<":\n";
t[i].display();
}

int ans;

ans= t[0].product(t[1]);
cout<<"\n\t\tSum of products of first & second tuple is : " <<ans;


}//main
