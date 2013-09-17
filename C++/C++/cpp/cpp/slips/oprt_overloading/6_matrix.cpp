#include<iostream>
using namespace std;

class matrix
{
 	int m, n;
  int **mat;
public:
   matrix ();
   matrix(int ,int);
  void accept ();
  void display();
int operator==(matrix &);
matrix& operator+(matrix & );
};

matrix::matrix (){}

matrix::matrix(int m1,int n1)
{
m=m1;
n=n1;
// int mat[m][n];
mat=new int*[m];
for(int i=0;i<m;i++)
mat[i]=new int[n];
}

matrix& matrix::operator+(matrix & m2)
{
	matrix temp(this->m,this->n);
	// of the order of matrix m1
if(this->m==m2.m && this->n==m2.n)
{
	for(int i=0;i<m;i++)
	  for(int j=0;j<n;j++)
	   temp.mat[i][j]= this->mat[i][j] + m2.mat[i][j];
}
return temp;
}//eof


int matrix::operator==(matrix &m2)
{
int cnt=0;
if(this->m ==m2.m && this->n ==m2.n)
{
	for(int i=0;i<m;i++) 
	{
	for(int j=0;j<n;j++) 
	{
		if(mat[i][j]== m2.mat[i][j])
		cnt++;
	}
}
}
if(cnt==(m*n))
return 1;
return 0;
}

void
matrix::accept ()
{
  cout << "\n\t\tEnter the order of matrix ";
  cin >> m >> n;

  mat = new int*[m];
  for (int i = 0; i < m; i++)
  mat[i] = new int[n];	//mat[i] contains a row of matrix

  for (int k = 0; k < m; k++)
    {
      for (int j = 0; j < n; j++)
	{
	  cout << "\n\t\tEnter element [" << k << "][" << j << "] : ";
	  cin >> mat[k][j];
	}
    }

}


void matrix::display()
{
for(int i=0;i< m;i++)
{
cout<<"\n";
for(int u=0;u <n;u++)
{
cout<<"\t"<<mat[i][u];
}

}

}

int
menu ()
{
  int ch;
  cout << "\n\t\t0)Exit";
  cout << "\n\t\t1)Add ";
  cout << "\n\t\t2)Equal ";
  cout << "\n\t\tEnter choice : ";
  cin >> ch;
  return ch;
}

main ()
{
  matrix m1, m2,m3;
  
  int ch;
  while ((ch = menu ()) != 0)
    {
      switch (ch)
	{
	case 1:
		
	  m1.accept ();
cout<<"\n\t\tFirst matrix you entered is :";
	  m1.display ();
	  m2.accept ();
cout<<"\n\t\tSecond matrix you entered is :";
	  m2.display ();
	
	m3=m1+m2;
	cout<<"\n\t\tThe addition is: \n\t";
	m3.display();		

        break;

	case 2:		//equal
	  m1.accept ();
cout<<"\n\t\tFirst matrix you entered is :";
	  m1.display ();
	  m2.accept ();
cout<<"\n\t\tSecond matrix you entered is :";
	  m2.display ();
	
	int c;
	c=(m1==m2);// m1 calls the operator= fun
	if(c==1)
	cout<<"\n\n\t\t Same2same";
	else
	cout<<"\n\t\tNot same";
	  break;

	default:
	  break;
	}			//swi
    }				//while
}
