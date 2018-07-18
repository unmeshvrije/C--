#include <iostream>
using namespace std;


class Hand {
    public:
       Hand() {
        cout << "DEFAULT Hand" << endl;
       }

       Hand(int a) {
        cout << "Special Hand" << endl;
       }
};

class Man
{
  private:
  float height;
  float weight;
  int i;
  char ch;
  double d;

  Hand hand;
  public:
  Man(float h, float w, int i, char ch, double d):height(h), weight(w), i(i), ch(ch), d(d), hand(3)
  {
   // Initializing the CONTAINed object in the initializer list saves you a call to the default CTOR.
   // hand = Hand(3);
  }

  void Show()
  {
cout << "Height: " << height <<endl;
cout << "Weight: " << weight << endl;
cout << "int: " << i << endl;
cout << "char: " << ch << endl;
cout << "double: " << d << endl;
  }
};

int main()
{
  Man m(5.10f, 70.0f, 5, 'A', 4.34);
  m.Show();
  return 0;
}
