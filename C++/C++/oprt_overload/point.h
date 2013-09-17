#include <iostream>

class Point
{
   private:

     public:
     int x;
     int y;
     Point();
     Point(int, int);
     ~Point();
     friend std::ostream& operator << (std::ostream&, Point&);

     void *operator new(size_t , void*);
     void *operator new(size_t);
     void operator delete(void *);
          
};
