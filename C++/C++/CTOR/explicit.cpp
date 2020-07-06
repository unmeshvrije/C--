#include <iostream>

using namespace std;

class Integer
{
   private:
   int i;

  public:
  explicit Integer(int i)
  {
     this->i = i;
  }
  void Display()
  {
     cout << "i = " << i << endl;
  }
};

void fun(Integer RefI)
{
  RefI.Display();
}

int main()
{
  //  fun(9);
 //  fun(new Integer(9));
    fun(Integer(9));
    Integer I(5);
    I.Display();
   return 0;
}
