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
void operator-();
matrix& operator-(matrix & );
};

matrix::matrix ()
{
}

matrix::matrix(int m1,int n1)
{
m=m1;
n=n1;
mat=new int*[m];
for(int i=0;i<m;i++)
mat[i]=new int[n];
}

matrix& matrix::operator-(matrix & m2)
{
matrix temp(m,n);
if(m==m2.m && n==m2.n)
{
	for(int i=0;i<m;i++)
	  for(int j=0;j<n;j++)
	    temp.mat[i][j]= mat[i][j] - m2.mat[i][j];
	

	
}
return temp;
}//eof


void matrix::operator-()
{
int cnt=0;
	for(int i=0;i<m;i++) 
	  for(int j=0;j<n;j++) 
	   this->mat[i][j]= (-1)*mat[i][j];
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
  cout << "\n\t\t1)Subtraction of two matrices ";
  cout << "\n\t\t2)Negate the matrix ";
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

	m3=m1-m2;
cout<<"\n\t\tThe Subtraction is: \n\t";
m3.display();		

        break;

	case 2:		//equal
	  m1.accept ();
cout<<"\n\t\tFirst matrix you entered is :";
	  m1.display ();

	-m1;//calls operator-()

m1.display();	  
break;
	default:
	  break;
	}			//swi

    }				//while
}
