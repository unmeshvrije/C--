#include "integer.h"

Integer::Integer()
{
   i = 0;
}

Integer::Integer(int i)
{
   this->i = i;
}

Integer::Integer(Integer& temp)
{
   this->i = temp.i;  
}

Integer::~Integer()
{
  //std::cout << "Destroyed" << std::endl;
}

void
Integer::SetValue(int i)
{
   this->i = i;
}

int
Integer::GetValue(void)
{
   return i;
}
Integer&
Integer::operator++()
{
   this->i = this->i + 1;
   return (*this);
}
Integer&
Integer::operator++(int)
{
   Integer temp (*this);
   this->i = this->i + 1;
   return (temp);
}


ostream& 
operator<<(ostream &out,Integer&temp)
{
   out << temp.i;
   return out;
}
