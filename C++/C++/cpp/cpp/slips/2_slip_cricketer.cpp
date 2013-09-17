#include<iostream>
using namespace std;


class Cricketer
{
  private: // data members
  	int code,runs,innings,no_of_not_outs;
	char name[20];
	float avg;

 public :
 
 	void getData()
	{
	  cout<<endl <<"Enter code of player :";
	  cin >> code;
	  cout<<"Enter name of player :";
	  cin >> name;
	  cout<<"Enter runs of player :";
	  cin >> runs;
	  cout<<"Enter no_of_not_outs of player :";
	  cin >> no_of_not_outs;
	  cout<<"Enter innings of player :";
	  cin >> innings;
	}
 	void putData()
	{
	  cout <<" "<<code<<" "<<name <<" "<<innings<<" ";
	  cout<<" "<<runs<<" "<<no_of_not_outs<<" "<<avg;
	}
	
	char* getname() // char [] NOT ALLOWED
	{
		/*char temp[20];
		strcpy(temp,name);
		return temp; */
		return name;
	} 
	float calculateAverage();
	float static calculateAverage(Cricketer c[]);
	int getRuns()
	{
	  return runs;
	}
};

float Cricketer::calculateAverage()
{
	avg = (float) runs / (float)(innings- no_of_not_outs);
	return avg;
}

float Cricketer::calculateAverage(Cricketer c[])
{
	float sum=0.0;
	for(int i=0;i<3;i++)
	   sum+=c[i].calculateAverage();
	return (sum/3);
}
int menu()
{
  int choice;
  
  cout<<("\n\t 1) Enter details ");
  cout<<("\n\t 2) Display Average of single player ");
  cout<<("\n\t 3) Display Average of all players ");
  cout<<("\n\t 4) Sort ");
  cout<<("\n\t 5) Exit ");
  
  cout<<"\n\n\t\t Enter your choice :   ";
  cin >> choice;
  return choice;  
}

void sort(Cricketer c[])
{
  for(int i=0;i<3;i++)
  {
     if(c[i].getRuns() > c[i+1].getRuns())
     {
       Cricketer temp = c[i];
       c[i]=c[i+1];
       c[i+1] = temp;
     }
  }

  for(int i=0;i<3;i++)
    c[i].putData();
  
}

main()
{
  int choice;
  float avg_of_all;
  Cricketer c[10];
    choice =menu();
    while(choice != 5)
    {
    	switch(choice)
	{
	  case 1:
	  for(int i=0;i<3;i++)
	  {
	     cout<<endl<<"Enter details of player [" << i+1<< "] : ";
	     c[i].getData();
	  }
	  break;
	  case 2:
	  for(int i=0;i<3;i++)
	  {
	     cout<<endl<<"Avg of player  ";
	     char n[20];
	     strcpy(n, c[i].getname());
	     cout << n << ": ";
	     float temp = c[i].calculateAverage();
	     
	     cout << temp;
	  }
	  
	  break;
	  case 3:
	  avg_of_all= Cricketer::calculateAverage(c);
	  cout <<endl <<" avg _all= " <<avg_of_all;
	  break;
	  
	  case 4:
	  	sort(c);
	  break;
	  default: 
	  	cout <<" Invalid choice";
	  	break;
	}
	choice = menu();
		
    }
	

  return 0;
}
