#include <iostream>
#include <iomanip>
using namespace std;

#define EXCEPTION_MODEL_NO	101
#define EXCEPTION_PRICE		102
#define EXCEPTION_SIZE		103

class Television
{
   int ModelNo;
   float Price;
   int Size;

   public:

   friend istream& 
   operator>>(istream &in,Television &);
   friend ostream&
   operator<<(ostream &out,Television&);
};



istream& 
operator>>(
	istream &in,
	Television &tv
	)
{
  try
  {
    cout << endl << "Enter Model No:";
    in >> tv.ModelNo;
    if (tv.ModelNo > 9999 || tv.ModelNo < 0)
       throw EXCEPTION_MODEL_NO;

    cout << endl << "Enter Price:";
    in >> tv.Price;
    if (tv.Price < 0 || tv.Price > 5000)
       throw EXCEPTION_PRICE;

    cout << endl << "Enter Size:";
    in >> tv.Size;
    if (tv.Size < 12 || tv.Size > 70)
       throw EXCEPTION_PRICE;
  }
  catch(int iException)
  {
    switch (iException)
    {
        case EXCEPTION_MODEL_NO:
	cout << "Invalid Model number" << endl;
	break;
        case EXCEPTION_PRICE:
	cout << "Invalid Price" << endl;
	break;
        case EXCEPTION_SIZE:
	cout << "Invalid Size" << endl;
	break;
    }

    tv.ModelNo = tv.Size = 0;
    tv.Price = 0.0f;
  }
}

ostream&
operator << (
	ostream &out, 
	Television &tv
	)
{
   out << endl << "TeleVision:" << endl;
   out << setw(10)<< "Model No:" << tv.ModelNo << endl;
   out << setw(10) <<"Price:" << tv.Price << endl;
   out << setw(10) <<"Size:" <<tv.Size;
   out << endl;
}


int main()
{
  Television Tv;
  cin >> Tv;
  cout << Tv;
  return 0;
}
