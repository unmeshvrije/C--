#include <iostream>
#include <cstring>

using namespace std;

class Emp
{
   private:
   int EmpId;
   char name[20];
   mutable float salary;
   
   public:
   Emp(
     int id, 
     const char *name,
     float sal
     )
   {
      EmpId = id;
      strcpy(this->name, name);
      salary = sal;
   }

   void ShowEmp() const
   {
    cout << "EmpId : " << EmpId;
    cout << "Name  : " << name;
    cout << "Salary: " << salary;
   }

   void SetSalary(float sal)const
   {
      salary = sal;
   }
};

int main()
{
  const Emp e(1,"raj", 9000);
  e.ShowEmp();
  e.SetSalary(12000);
  cout << "After appraisal:" << endl;
  e.ShowEmp();
  cout<<endl;
  return 0;
}
