#include <iostream>
using namespace std;

class Man
{
  private:
  float height;
  float weight;
  int i;
  char ch;
  double d;

  public:
  Man(float h, float w, int i, char ch, double d):height(h), weight(w), i(i), ch(ch), d(d)
  {
     //height = h;
     //weight = w;
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
