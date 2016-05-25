#include <iostream>

using namespace std;

class RefCount
{
  private:
    int count;

  public:
    void add_ref() { count++;}
    int release() { return --count;}
};

template <typename T>
class SmartPointer
{
  private:
  T* ptr;
  RefCount *rc;

  public:
      SmartPointer() {
        rc = new RefCount();
        rc->add_ref();
      }

      SmartPointer(T* data): ptr(data), rc(0) {
        rc = new RefCount();
        rc->add_ref();
      }

      ~SmartPointer() {
        int r = rc->release();
        if (r == 0) {
          delete ptr;
          delete rc;
        }
      }

      T operator *() {
        return *ptr;
      }

      T* operator -> () {
        return ptr;
      }
};

int main(int argc, char *argv[])
{
  return 0;
}
