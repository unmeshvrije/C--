#include <cstring>
#include "string.h"


String::String()
{
   str = NULL;
   len = 0;
}

String::String(const char *str, int len)
{
   this->len = strlen(str);
   this->str = new char[this->len + 1];
   strcpy(this->str ,str);
}

String::String(const String& temp)
{
   this->len = strlen(temp.str);
   this->str = new char[this->len + 1];
   strcpy(this->str ,temp.str);   
}


String::~String()
{
   delete []str;
}

char *
String::GetString(void)
{
  return str;
}
