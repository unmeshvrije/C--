#include <iostream>
using namespace std;

/*template <typename T>
struct Node
{
   T data;
   struct Node *next;
};

struct <int> newnode;
*/

template <typename Generic, int Size>
class Stack
{
   private:
     int Top;
     Generic Elements[Size];

   public:
     Stack();
     bool Push(Generic item);
     Generic Pop();
     void Display();
};

/*
Type argument
NonType argument
Template argument
*/

template <typename Generic, int Size>
Stack<Generic, Size>::Stack()
{
   cout << "Stack::CTOR" << endl;
   cout << "size = " << Size << endl;
   Top = -1;
}

//bool Stack::Push(int t)

template <typename Generic, int Size>
bool Stack<Generic, Size>::Push(Generic item)
{
   if (Top >= Size-1)
   {
     cout << "Stack Overflow..." << endl;
     return false;
   }

   Elements[++Top] = item;
   return true;
}


template <typename Generic, int Size>
Generic Stack<Generic, Size>::Pop()
{
   Generic temp;

   if (-1 == Top)
   {
      cout << "Stack Underflow...";
      return (Generic)0;
   }

   temp = Elements[Top];
   --Top;
   return temp;
}

template <typename Generic, int Size>
void Stack<Generic, Size>::Display()
{
  int i;
  for (i = Top; i >= 0; --i)
     cout << Elements[i] << endl;
}


int Menu()
{
   int choice;
   cout << "\t1) Push" << endl;
   cout << "\t2) Pop" << endl;
   cout << "\t3) Display" << endl;
   cout << "\t4) Exit" << endl;
   cout << endl << "\tEnter your choice : ";
   cin >> choice;
   return choice;
}

int
 main()
{
   int item;
   //char item;
   int choice;
   Stack <int, 5> stk;//Should create 5 item stack
   //Stack <char, 20> stk;//Should create 20 item stack

   while (1)
   {
      choice = Menu();
      if (4 == choice)
      {
         break;
      }

      switch(choice)
      {
         case 1:
	 {
    cout << endl << "Enter item: ";
	    cin >> item;
	    stk.Push(item);
	    break;
	 }

         case 2:
	 {
    cout << endl<< "Popped item: " << stk.Pop();
	    break;
	 }

         case 3:
	 {
	    stk.Display();
	    break;
	 }

         default: break;
      }
   }

   return 0;
}
