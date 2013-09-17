#include <iostream>
#include <malloc.h>
#include "point.h"

using namespace std;

Point::Point(){}

Point::~Point(){}

Point::Point(int a, int b) : x(a), y(b)
{
  cout << "PARAM CTOR" << endl;
}

void *
Point::operator new (size_t sz, void *p)
{
  cout << "In placement new" << endl;
   return (Point*)p;
}

void*
Point::operator new (size_t size)
{
   cout << "In operator new" << endl;
   return malloc(size);
}

void
Point::operator delete(void *ptr)
{
   cout << "In operator delete" << endl;
   free(ptr);
}
