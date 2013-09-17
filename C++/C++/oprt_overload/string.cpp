using namespace std;
#include <cstring>
#include "string.h"


String::String()
{
   cout << "Default CTOR" << endl;
   str = NULL;
   len = 0;
}

String::String(const char *str, int len)
{
   cout << "PARAM CTOR" << endl;
   this->len = strlen(str);
   this->str = new char[this->len + 1];
   strcpy(this->str ,str);
}

String::String(const String& temp)
{
   cout << "COPY CTOR" << endl;
   this->len = strlen(temp.str);
   this->str = new char[this->len + 1];
   strcpy(this->str ,temp.str);   
}


String::~String()
{
   cout << "DTOR" << endl;
   delete []str;
}

char *
String::GetString(void)
{
  return str;
}

String&
String::operator= (String &temp)
{
   //
   //	If "this" string object 
   //	is already allocated a string
   //	then free it
   //
   if (NULL != this->str)
     delete [] this->str;

   this->len = strlen(temp.str);
   this->str = new char[this->len + 1];
   strcpy(this->str ,temp.str);   
   return (*this);
}

/*s1 = ram
s2 = rao
s3 = s1 + s2;

s3 = ramrao*/

//
// Chaining of + operator 
// not supported as "static"
// temporary variable is returned
//
String&
String::operator+ (String &temp)
{
  static String Result;

  Result.len =this->len+temp.len;
  Result.str = new char [Result.len + 1];
  strcpy(Result.str, this->str);
  strcat(Result.str, temp.str);
  return Result;
}

void
String::operator+=(String &s2)
{
   String temp(*this);

   delete [] this->str;
   this->str = new char[this->len + s2.len + 1];
   this->len += s2.len;
   strcpy(this->str, temp.str);
   strcat(this->str, s2.str);
   return;
}

int
String::operator==(String &temp)
{
 return !strcmp(this->str, temp.str);
}

char&
String::operator[](int index)
{
   if (index >= this->len)
     return this->str[0];

   return this->str[index];
}

ostream&
operator << (ostream& out, String &s)
{
   out << s.str;
   return out;
}

istream&
operator >> (istream& in, String &s)
{
   char str[50];
   in >> str;
   s.len = strlen(str);
   s.str= new char [s.len+ 1];
   strcpy(s.str,str);
   return in;
}

