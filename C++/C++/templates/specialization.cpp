#include <iostream>

using namespace std;

class List
{
   public:
   void add(){ cout << "List::add()" << endl;}
};

class Array
{

  public:
  void add() {cout << "Array::add()" << endl;}
};

class Container
{
   public:
   void insert(){ cout << "Container::insert()" << endl;}
};


template <typename Generic>
class Adapter
{

    public:

    void add(Generic Obj){
     cout << "Generic Add" << endl;
Obj.add();
}
};

/*
Template sepcialization
*/

template<>
void Adapter<Container>::add(Container c)
{
   cout << "Special add" << endl;
   c.insert();
}

int main()
{
   List l;
   Adapter<List> ListAdapt;
   ListAdapt.add(l);

   Array a;
   Adapter<Array> ArrayAdapt;
   ArrayAdapt.add(a);

   Container c;
   Adapter<Container> ContainerAdapt;
   ContainerAdapt.add(c);
   return 0;
}
