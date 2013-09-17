#include"iostream"

//using namespace std;


// :: is scope resolution operator

int main()
{
  int a,b;
  std::cout<<"Enter two numbers : ";
  std::cin >> a >> b;
  //std::cin >> b;
/*  if(a>=b)
    std::cout <<a;
 else 
    std::cout<<b;
  */  
  std::cout << "\nSum of " << a <<" and "<<b <<" is "<< a+b;
   
  return 0;
}
