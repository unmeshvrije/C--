#include<iostream>
#include<vector>
#include<algorithm>
#include<sstream>

using namespace std;

template<typename T>
void print_vector(std::vector<T>& vec)
{
  for (typename vector<T>::const_iterator it = vec.begin(); it != vec.end(); ++it) {
    cout << *it;
    if (it+1 != vec.end()) {
      cout << ", ";
    }
  }
  cout << endl;
}

void swap(int &a, int &b)
{
  int t = a;
  a = b;
  b = t;
}

/**
 * 1 2 3
 * 2 1 3
 * 3 2 1
 *
 *
 * a b c d 
 *
 * temp = arr[0]
 * i = 0, j = arr.size()-1
 * while (i < n-1 && j > 0) {
 *    arr[i] = arr[j]
 *    i++;
 *    j--;
 *    }
 * 
 *
 *
 * */

void generate_all_permutations(vector<int>& toBePermuted, int nextIndex)
{
  if (nextIndex == toBePermuted.size()){
    print_vector(toBePermuted);
    return;
  }

  for (int i = nextIndex; i < toBePermuted.size(); ++i) {
    swap(toBePermuted[i], toBePermuted[nextIndex]);
    generate_all_permutations(toBePermuted, nextIndex+1);
    swap(toBePermuted[i], toBePermuted[nextIndex]);
  }
}

void generate_all_permutations_dup(vector<int>& toBePermuted, int nextIndex, vector<bool>& used)
{
  if (nextIndex == toBePermuted.size()){
    print_vector(toBePermuted);
    return;
  }

  for (int i = nextIndex; i < toBePermuted.size(); ++i) {
    if ( (!used[i]) && (i == nextIndex || toBePermuted[i] != toBePermuted[nextIndex]) ) {
      used[i] = true;
      swap(toBePermuted[i], toBePermuted[nextIndex]);
      generate_all_permutations(toBePermuted, nextIndex+1);
      swap(toBePermuted[i], toBePermuted[nextIndex]);
      used[i] = false;
    }
  }
}


int fact(int n)
{
  if (n == 1) {
    return 1;
  }

  return n * fact(n-1);
}

void permutation_sequence(int n, int k)
{
  vector<int> nums;
  for (int i = 1; i <= n; ++i) {
    nums.push_back(i);
  }

  vector<int> sequence;
  int f = fact(n);

  for (int bits = n; bits >= 1; --bits) {
    f /= bits;
    int digit = (k-1)/f;
    sequence.push_back(nums[digit]);
    nums.erase(nums.begin() + digit);
    k = k - (digit * f);
  }

  print_vector(sequence);
}

void permute (int n)
{
  vector<int> nums;
  for (int i = 1; i <= n; ++i) {
    nums.push_back(i);
  }

  int arr [] = {1,1,2};
  vector<int> vec(arr, arr + sizeof(arr)/sizeof(arr[0]));

  print_vector(vec);
  cout << "***********" << endl;
  vector<bool> used(vec.size(), false);

  generate_all_permutations_dup(vec, 0, used);
  //generate_all_permutations(nums, 0);

  // Following will generate all permutations that are in order (ascending)
  /*
   for (int i = 1; i <= fact(n); ++i) {
    permutation_sequence(n, i);
  }
  */
}

int main(int argc, char *argv[])
{
  if (argc != 2) {
    cerr << "Number input expected." << endl;
    return -1;
  }

  int n;
  stringstream ss(argv[1]);
  ss >> n;
  permute(n);
  return 0;
}
