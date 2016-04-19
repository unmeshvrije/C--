#include <iostream>
using namespace std;

class String
{
   private:
     char *str;
     int len;

   public:
     String();
     String(const String& temp);
     String(const char *str, int len);
     ~String();
     String& operator=(String &temp);
     String& operator+(String &temp);
     void operator+=(String &temp);
     int operator==(String& temp);
     char& operator[](int index);
     char* GetString(void);

     friend ostream&    operator <<(ostream&, String&);
     friend istream&     operator >>(istream&, String&);

};







