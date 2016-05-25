#include <iostream>
#include <vector>
#include <algorithm>
#include<cstdlib>
#include <assert.h>

using namespace std;

void print_vector(std::vector<int>& vec)
{
  cout << " [ ";
  for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it)
  {
    cout << *it << " ";
  }
  cout << " ] ";
  cout << endl;
}

int min_patches(std::vector<int>& arr, int n)
{
  int patches = 0;
  char choice;
  while (1) {
    int length = arr.size();
    int n_bits = 1 << length;

    std::cout << "length = " << length << " and n_bits = " << n_bits << std::endl;
    std::cout << "continue ? (y/n)";
    std::cin >> choice;
    if (choice == 'n')
      break;

    std::vector< std::vector<int> > result;
    for (int i = 0; i < n_bits; ++i)
      result.push_back(std::vector<int>());

    for (int i = 0; i < n_bits; ++i) {
      for (int j = 0; j < length; ++j) {
        if (i & (1 << j)) {
          result[i].push_back(arr[j]);
        }
      }
    }

    bool done = false;
    vector<int> all_sums;
    for (int i = 0; i < n_bits; ++i) {
      int sum = 0;
      for (std::vector<int>::const_iterator it = result[i].begin(); it != result[i].end(); ++it) {
        sum += (*it);
      }
      std::cout << "Sum: " << sum << endl;
      all_sums.push_back(sum);
    }

    sort(all_sums.begin(), all_sums.end());
    int prev = 0;
    for (std::vector<int>::const_iterator it = all_sums.begin(); it != all_sums.end(); ++it){

      int sum = *it;
      if (sum == prev || sum == prev+1) {
        // No hole
        prev = sum;
        std::cout << "No hole, prev = " << prev << std::endl;
        if (sum == n) {
          done = true;
          break;
        }
      } else {
        // Add prev +1 to the original vector and increment the patch count
        cout << "hole found, prev = " << prev << endl;
        patches++;
        done = false;
        break;
      }
    }

    if (done) {
      break;
    }

    cout << "prev outside of for is " << prev << std::endl;
    arr.push_back(prev+1);
    std::sort(arr.begin(), arr.end());
    std::cout << "*****************" << std::endl;
    print_vector(arr);
    std::cout << "*****************" << std::endl;
  }

  return patches;
}

int main(int argc, char *argv[])
{
  std::vector<int> arr;
  int length = atoi(argv[1]);
  for (int i = 0; i < length; ++i) {
    assert(argc > i+2);
    arr.push_back(atoi(argv[i+2]));
  }

  int n = atoi(argv[argc-1]);

  cout << "Number of patches : " << min_patches(arr, n) << endl;
  return 0;
}
