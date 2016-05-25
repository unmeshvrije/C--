#include<iostream>

using namespace std;

void swap(int&a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

bool greater(int a , int b) {
  return (a > b);
}

bool smaller(int a, int b) {
  return (a < b);
}

class Heap {

  protected:
    int* array;
    int heapsize;
    bool (*comparator)(int,int);

  public:
    Heap(int* arr, bool(*comp)(int, int)) : array(arr), comparator(comp){
      heapsize = -1;
    }

    virtual ~Heap() {
      if (array) {
        delete[] array;
      }
    }

    // Interfaces for heap ADT:
    virtual bool insert(int e) = 0;
    virtual int getTop() = 0;
    virtual int extractTop() = 0;
    virtual int getCount() = 0;

  protected:
    int left(int i) {
      return 2*i + 1;
    }

    int right (int i ) {
      return 2*i + 2;
    }

    int parent(int i) {
      if (i <= 0) {
        return -1;
      }

      return (i-1)/2;
    }

    int top(void) {
      int max = -1;
      if (heapsize >= 0) {
        max = array[0];
      }
    }

    int count(void) {
      return heapsize+1;
    }

    void heapify(int i) {
      int l = left(i);
      int r = right(i);

      if (l < heapsize && comparator(array[i], array[l])) {

      }
      if (p >= 0 && comparator(array[i], array[p])) {
        swap(array[i], array[p]);
        heapify(p);
      }
    }

    int deleteTop() {
      int del = -1;
      if (heapsize > -1) {
        del = array[0];
        swap(array[0], array[heapsize]);
        heapsize--;
        heapify(parent(heapsize+1));
      }
    }

    bool insertHelper(int key) {
      bool ret = false;
      if (heapsize < MAX_HEAP_SIZE) {
        ret = true;
        heapsize++;
        array[heapsize] = key;
        heapify(heapsize);
      }
    }
};


class MaxHeap: public Heap {
  private:
  public:
    MaxHeap(): Heap(new int[MAX_HEAP_SIZE], &greater){}
    ~MaxHeap(){}

    int getTop() {
      return top();
    }

    int extractTop() {
      return deleteTop();
    }

    int getCount() {
      return count();
    }

    bool insert(int key) {
      return insertHelper(key);
    }  
};
