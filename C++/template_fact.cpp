#include <iostream>

using namespace std;

template <int n>
struct Factorial
{
  enum result {value = n * Factorial<n-1>::value};
};

template <>
struct Factorial<0>
{
  enum result {value = 1};
};

int main(void)
{
  int n;
  cout << "Enter number:";
  cin >> n;
  cout << endl;
  cout << Factorial<5>::value << endl;
  return 0;
}
