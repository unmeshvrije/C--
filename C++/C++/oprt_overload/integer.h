#include <iostream>
using namespace std;

class Integer
{
   private:
     int i;

   public:

   Integer();
   Integer(int);
   Integer(Integer&);
   ~Integer();

   void SetValue(int);
   int GetValue(void);
   friend ostream&
   operator << (ostream&, Integer &);

   Integer& operator++();
   Integer& operator++(int);
};

