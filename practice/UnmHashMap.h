#include<iostream>

template <typename Key, typename Value>
class UnmHashMap {
  private:

    unsigned long long BUCKET_SIZE;;
    double load_factor;

    struct ListNode {
      Key key;
      Value val;
      ListNode* next;
      ListNode(Key k, Key v):key(k),val(v){next = NULL;}
    };

    struct List {
      ListNode* head;
      ListNode* tail;
      List();
      ~List();
      std::pair<Value, bool> lookup(Key k);
      bool insert(Key k, Value v);
      bool remove(Key k);
      void display();
    };

    List* buckets;

    // Takes key as input and gives the index into the bucket array
    unsigned long long hash(Key k);
  public:

    UnmHashMap();
    ~UnmHashMap();
    bool insert(Key k, Value v);
    std::pair<Value, bool> lookup(Key k);
    bool remove(Key);
    void display();
};
