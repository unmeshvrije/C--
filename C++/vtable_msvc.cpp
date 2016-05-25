#include <iostream>

using namespace std;


#define	CREATE_OBJECT_ON_HEAP	0
#define	CREATE_OBJECT_ON_STACK	0

#define	DIAMOND_PROBLEM	0

#define	MI_PRINT_VFTABLE_USING_THIS	1

#if MI_PRINT_VFTABLE_USING_THIS
#include "mi.h"
#endif


#if DIAMOND_PROBLEM


class A
{
	public:
		int a;
		A(){cout<<"Hello A"<<endl;}
};


class B : virtual public A
{
	public:
		int b;
		B(){cout<<"Hello B"<<endl;}
};


class C : virtual public A
{
	public:
		int c;
		C(){cout<<"Hello C"<<endl;}
};


class D : public B, public C
{
	public:
		int d;
		D(){cout<<"Hello D"<<endl;}
};



#endif

class Base
{
	public:

		Base(){cout << "Hello Base" <<endl;}

	virtual void fun(){cout<< "Base::fun"<<endl;}
	virtual void gun(){cout<< "Base::gun"<<endl;}
	virtual void hun(){cout<< "Base::hun"<<endl;}
	virtual void iun(){cout<< "Base::iun"<<endl;}

};

class Derived : public Base
{

public:
	Derived(){cout << "Hello Drived" <<endl;}

	virtual void fun(){cout<< "Derived::fun"<<endl;}
	virtual void gun(){cout<< "Derived::gun"<<endl;}

	int i;

};


int
main(
	)
{

	//
	//	Object on heap.
	//

	#if CREATE_OBJECT_ON_HEAP
	
	Derived*ptr = new Derived();

	/*Derived*ptr2 = new Derived();
	ptr->fun();

	ptr2->fun();*/
	int *vptr = *(int **)(ptr);	//Take virtual table address into local variable.
	//int *vptr = ptr;

	((void(*)()) (vptr[0]))();	//Derived::fun as Derived has overridden fun
	((void(*)()) (vptr[1]))();	//Derived::gun as Derived has overridden gun
	((void(*)()) (vptr[2]))();	//Base::hun as Derived has NOT OVERRIDDEN hun
	((void(*)()) (vptr[3]))();	//Base::iun as Derived has NOT OVERRIDDEN iun


	/*Base b;
	Derived *ptr = static_cast<Derived*>(&b);
	ptr->fun();*/
	

	/*
	void (*pfn)();
	pfn = vptr[0];
	pfn();
	*/
	#endif


	#if CREATE_OBJECT_ON_STACK

	Derived d;
	int *vptr = *(int**)(&d);
	//int *vptr = (int*)(&d);

	((void(*)()) (vptr[0]))();
	((void(*)()) (vptr[1]))();

	#endif


	#if DIAMOND_PROBLEM

	D obj;			// Constructors called in sequence: A->B->A->C->D (when No virtual inheritance is used)
					// Constructors called in sequence: A->B->   C->D (when virtual inheritance is used)
	obj.a = 3;


	#if MI_PRINT_VFTABLE_USING_THIS
	B ObjB;
	int *This = (int*)&ObjB;
	#endif

#endif

#if MI_PRINT_VFTABLE_USING_THIS

	typedef void (*pfn)(void);
	B ObjB;

	cout << "Sizeof Object of B = " << sizeof(ObjB) << endl;

	int *This;
	This = (int*)&ObjB;

	//
	//	First entry in B's object: B's VPTR-> B's only function: bun()
	//
	pfn BVf1 = (pfn)*(	(int*)*((int*)(&ObjB) + 0));
	BVf1();

	//
	//	Second entry in B's object: B's VB PTR-> Offset
	//
	cout << *(	((int*)*(((int*)(&ObjB))	+ 1)) + 0) << endl;
	cout << *(	((int*)*(((int*)(&ObjB))	+ 1)) + 1) << endl;

	//
	//	Third entry in B's object: B's data member
	//
	cout << *(((int*)&ObjB) + 2) << endl;

	//
	//	Forth entry in B's object: A's VBPTR (may be)-> Offset
	//
	cout << *(	(int*)*((int*)(&ObjB))	+ 3) << endl;

	//
	//	Fifth entry in B's object: A's VFPTR -> (Copied for B)
	//
	pfn AVf1 = (pfn)*(	((int*)*((int*)(&ObjB) + 4) ));
	AVf1();

	pfn AVf2 = (pfn)*(	((int*)*((int*)(&ObjB) + 4) ) + 1);
	AVf2();

	pfn AVf3 = (pfn)*(	((int*)*((int*)(&ObjB) + 4) ) + 2);
	AVf3();

	pfn AVf4 = (pfn)*(	((int*)*((int*)(&ObjB) + 4) ) + 3);
	AVf4();

	//
	//	Sixth entry in B's object: A's data member
	//
	cout << *(((int*)&ObjB) + 5);

#endif
}
