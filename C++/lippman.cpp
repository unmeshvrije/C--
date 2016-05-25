#include <iostream>
#include <iomanip>

using namespace std;

class X
{
  friend istream & operator>> (istream &, X&);
  friend ostream & operator<< (ostream&, X&);
  public:
  X (int sz=1024) { ptr = new char[sz];}

  private:
  char *ptr;

};


istream& operator>> (istream &in, X& x)
{
  in >> x.ptr;
  return in;
}

ostream& operator << (ostream &out, X& x)
{
  out << x.ptr;
  return out;
}

X buf;

int main()
{
  cin >> setw(1024) >> buf;
  cout << buf;
}
