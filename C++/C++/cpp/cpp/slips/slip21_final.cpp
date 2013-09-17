#include <iostream>
#include <fstream>
using namespace std;
class emp
{
	private:
		int eid;
		char ename[10];
		float esalary;
	public:
		void Getdata()
		{
			cout << "\n\tEnter Emp Details :\n";
			cout << "\tEmp id : "; cin >> eid;
			cout << "\tEmp Name : "; cin >> ename;
			cout << "\tEmp Salary : "; cin >> esalary;
		}
		
		void Putdata()
		{
			cout << "\n\t" << eid << "\t" 
				  << ename << "\t" 
				  << esalary;
		}
		
		void AppendtoFile(fstream &file)
		{
			file.clear();// set state variable to 0
			file.seekg(0,ios::end);
			file << eid << "\t" 
				  << ename << "\t" << esalary << "\n";
		}
		
		void DisplayFile(fstream &file)
		{
			file.clear();
			file.seekg(0,ios::beg);
			while(1)
			{
				file >> eid >> ename >> esalary;
				if(file.eof())
					break;
				Putdata();
			}
		}
		
		void DeleteRecord(fstream &file,int tid)
		{
			char DeletedFlag='n';
			fstream TempFile("temp.txt",ios::out);
			
			//file is pointer to
			//the file
	// whose record is to be deleted
			file.clear();
			file.seekg(0,ios::beg);
			
			while(1)
			{
			file >> eid >> ename >> esalary;
			if(file.eof())
				break;
			if(eid != tid)
				{
				TempFile << eid << "\t" << ename << "\t" << esalary << "\n";
				}
			else
			if(eid == tid)
				{
				DeletedFlag='y';
				}
			}
			TempFile.close();
			if(DeletedFlag == 'n')
			{
				remove("temp.txt");
				cout << "\n\tNot Deleted";
				getchar();
				getchar();
			}
			else
			if(DeletedFlag == 'y')
			{
			file.close();
			remove("emp.txt");
			rename("temp.txt","emp.txt");
			file.open("emp.txt",ios::in | ios::out);
			}
		}

		void ModifyRecord(fstream &file,int tid)
		{
			char ModifyFlag='n';
			fstream TempFile("temp.txt",ios::out);
			
			file.clear();
			file.seekg(0,ios::beg);
			
			while(1)
			{
			file >> eid >> ename >> esalary;
			if(file.eof())
				break;
			if(eid == tid)
				{
				ModifyFlag='y';
				cout << "\n\tFollowing Record Found\n";
				Putdata();
				cout << "\n\tEnter New Details :\n";
				Getdata();
				}
			
			TempFile << eid << "\t" << ename << "\t" << esalary << "\n";
			}
			
			TempFile.close();
			if(ModifyFlag == 'n')
			{
				remove("temp.txt");
				cout << "\n\tNot Modified";
				getchar();
				getchar();
			}
			else
			if(ModifyFlag == 'y')
			{
			file.close();
			remove("emp.txt");
			rename("temp.txt","emp.txt");
			file.open("emp.txt",ios::in | ios::out);
			}
		}
};

int menu()
{
	int ch;
	system("clear");
	cout << "\n\t0) Exit";
	cout << "\n\t1) Append";
	cout << "\n\t2) Modify";
	cout << "\n\t3) Delete";
	cout << "\n\t4) Display";
	cout << "\n\tEnter Choice :";
	cin >> ch;
	return ch;	
}

int main()
{
	emp o;
	fstream file;
	int ch;
	
	file.open("emp.txt",ios::in);
	
	if(file.rdstate() != 0)       
		{
		file.clear();        
		file.open("emp.txt",ios::out);
		}

	file.close(); 
	
	file.open("emp.txt",ios::in | ios::out);
	while((ch=menu())!=0)
	{
		if(ch==1)
			{
			o.Getdata();
			o.AppendtoFile(file);
			}
		else
		if(ch==4)
			{
			o.DisplayFile(file);
			getchar();
			getchar();
			}
		else
		if(ch==3)
			{
			int tid; 
			cout << "\n\tEnter Id : "; cin >> tid;
			o.DeleteRecord(file,tid);
			}
		else
		if(ch==2)
			{
			int tid;
			cout << "\n\tEnter Id : "; cin >> tid;
			o.ModifyRecord(file,tid);
			}
	}
}
