#include<iostream>
using namespace std;


class String
{
    int length;
    char *str;
    
    void getString(int length)
    {
     	this->length = length;
	
    }
};



main()
{
  String s1,s2,s3;
  s1.getString(4);
  s2.getString(5);
  s3.getString(6);

}