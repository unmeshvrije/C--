#include <iostream>
using namespace std;

class A
{
   private:
   int a;

   public:
   virtual void fun()
   {
      cout << "A::fun()" << endl;
   }
};

class B : public virtual A
{
   int b;
   public:
   virtual void fun()
   {
      cout << "B::fun()" << endl;
   }
   virtual void gun()
   {
      cout << "B::gun()" << endl;
   }
};

class C : public virtual A
{
   int c;
   public:
   virtual void fun()
   {
      cout << "C::fun()" << endl;
   }
   virtual void hun()
   {
      cout << "C::hun()" << endl;
   }
};

class D : public B, public C
{
   int d;
   public:
   virtual void fun()
   {
      cout << "D::fun()" << endl;
   }
   virtual void iun()
   {
      cout << "D::iun()" << endl;
   }
};


typedef void(*vfptr)();

int main()
{
   D Obj;
   /*Obj.a = 1;
   Obj.b = 2;
   Obj.c = 3;
   Obj.d = 4;*/
   vfptr f1,f2,f3,f4;
   int *VfTable;
//   cout << "sizeof(D)=" << sizeof(Obj);
//   cout << endl;
   int *pObj = (int*)(&Obj);
   cout << "At " << *(pObj+0);
   cout << endl;
   VfTable = (int*)(*(pObj+0));
   f1 = (vfptr)(*VfTable);
   f2 = (vfptr)(*(VfTable + 1));
   f3 = (vfptr)(*(VfTable + 2));
   cout << "\t"; f1();
   cout << "\t"; f2();
   cout << "\t"; f3();

   *(pObj+1) = 22;
   cout <<  *(pObj+1) << endl;

   cout << "At " << *(pObj+2);
   cout << endl;
   VfTable = (int*)(*(pObj+2));
   f1 = (vfptr)(*VfTable);
   f2 = (vfptr)(*(VfTable + 1));
   cout << "\t"; f1();
   cout << "\t"; f2();

   *(pObj + 3) = 33;
   *(pObj + 4)=  44;
   cout <<  *(pObj+3) << endl;
   cout <<  *(pObj+4) << endl;

   cout << "At " << *(pObj+5);
   cout << endl;
   VfTable = (int*)(*(pObj+5));
   f1 = (vfptr)(*VfTable);
   cout << "\t"; f1();

   *(pObj+6) = 11;
   cout <<  *(pObj+6) << endl;
   return 0;  
}
