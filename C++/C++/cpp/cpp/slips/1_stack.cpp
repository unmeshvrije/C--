#include<iostream>
using namespace std;
#include"stack.h"
Stack::Stack ()
{
  top = -1;
}
void
Stack::push (char ch)
{
  data[++top] = ch;
  //data[0] = ch
  //data[1] = ch;
}

char
Stack::pop ()
{
  char ch;
  ch = data[top];
  top--;
  return ch;
}

void
Stack::display ()
{
  char ch;
  if (top == -1)
    cout << "\n\t\tStack is empty...";
  else
    {
      while (top != -1)
	{
	  ch = pop ();
	  cout << ch;
	}
    }
}

int
main ()
{
  char arr[100];
  Stack s;
  cout << "Enter the string : ";
  cin.getline (arr, 100);//cin takes 'space' as a delimiter, we use getline('\n' is delimiter)
  for (int i = 0; arr[i] != '\0'; i++)
    {
    
      if (arr[i] == ' '||arr[i]=='\t')
	{
	  s.display ();
	  cout <<arr[i];// to print the delimiter otherwise output is saturated
	}
      else
      
	s.push(arr[i]);
    }
s.display(); //when a string ends prog comes out of loop hence,last word would not be printed
}
