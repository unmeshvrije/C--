#include<iostream>
#include<cassert>
#include<typeinfo>
#include"UnmHashMap.h"

#define INT_HASH 1
#define STRING_HASH 0

using namespace std;

template <typename Key, typename Value>
UnmHashMap<Key, Value>::List::List() {
  head = NULL;
  tail = NULL;
}

template <typename Key, typename Value>
UnmHashMap<Key, Value>::List::~List() {
  
}

template <typename Key, typename Value>
bool UnmHashMap<Key, Value>::List::insert(Key k, Value v) {
    ListNode *newnode = new ListNode(k, v);
    if (head == NULL && tail == NULL) {
      head = tail = newnode;
      return true;
    }
    assert(tail != NULL);
    tail->next = newnode;
    tail = newnode;
    return true;
}

template <typename Key, typename Value>
std::pair<Value, bool> UnmHashMap<Key, Value>::List::lookup(Key k) {
  ListNode *nav = head;
  while (nav) {
    if (nav->key == k) {
      return make_pair(nav->val, true);
    }
    nav = nav->next;
  }
  return make_pair((Value)0, false);
}

template <typename Key, typename Value>
void UnmHashMap<Key, Value>::List::display() {
  ListNode *nav = head;
  while(nav) {
    cout << "[" << nav->key << ", " << nav->val << "]";
    if (nav->next) {
      cout << "=>";
    }
    nav = nav->next;
  }
  cout << endl;
}

template <typename Key, typename Value>
bool UnmHashMap<Key, Value>::List::remove(Key k) {
  ListNode *prev = head;
  ListNode *nav = head;

  // Delete first element
  if (head->key == k) {
    head = head->next;
    delete prev;
    return true;
  }

  bool found = false;
  while (nav != NULL) {
    prev = nav;
    nav = nav->next;
    if (nav->key == k) {
      found = true;
      break;
    }
  }

  if (!found) {
    return false;
  }

  // Delete last element
  if (!nav) {
    delete prev;
    return true;
  }

  prev->next = nav->next;
  delete nav;
  return true;
}

/* Attempt of specialization
template<> 
unsigned long long UnmHashMap<int, int>::hash(int n) {
  return n % BUCKET_SIZE;
}
*/

template <typename Key, typename Value>
unsigned long long UnmHashMap<Key, Value>::hash(Key k) {
  if (typeid(Key) == typeid(int)) {
    return k % BUCKET_SIZE;
  }

  return 0;
}

template <typename Key, typename Value>
UnmHashMap<Key, Value>::UnmHashMap() {
  BUCKET_SIZE = 10;
  buckets = new List[BUCKET_SIZE];
  for (int i = 0; i < BUCKET_SIZE; ++i) {
    buckets[i] = List();
  }
}

template <typename Key, typename Value>
UnmHashMap<Key, Value>::~UnmHashMap() {
  for (int i = 0; i < BUCKET_SIZE; ++i) {
    // Properly delete each list
  }
  // Delete array of pointers
  delete[] buckets;
}

template <typename Key, typename Value>
bool UnmHashMap<Key, Value>::insert(Key k, Value v) {
  unsigned long long index = hash(k);
  return buckets[index].insert(k, v);
}

template <typename Key, typename Value>
bool UnmHashMap<Key, Value>::remove(Key k) {
  unsigned long long index = hash(k);
  return buckets[index].remove(k);
}

template<typename Key, typename Value>
std::pair<Value, bool> UnmHashMap<Key, Value>::lookup(Key k) {
  unsigned long long index = hash(k);
  std::pair<Value, bool> result = buckets[index].lookup(k);
  return result;
}

template <typename Key, typename Value>
void UnmHashMap<Key, Value>::display() {
  for (int i = 0; i < BUCKET_SIZE; ++i) {
    cout << i << ":";
    buckets[i].display();
  }
}

int main() {
  #if INT_HASH
  UnmHashMap<int, int> umap;
  umap.insert(2,109);
  umap.insert(3,537);
  umap.insert(13,78);
  umap.insert(43,566);
  umap.insert(35,23);
  umap.insert(36,11);
  umap.insert(38,576);
  umap.insert(39,557);
  umap.insert(312,157);
  umap.insert(139,7);
#endif

  #if STRING_HASH
  UnmHashMap <string, int> umap;
  umap.insert("cat", 1);
  umap.insert("dog", 2);
  umap.insert("hog", 3);
  umap.insert("lot", 4);
  umap.insert("hot", 5);
  umap.insert("dot", 6);
  #endif

  umap.display();
}
