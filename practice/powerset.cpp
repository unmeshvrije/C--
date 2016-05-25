#include <iostream>
#include <vector>

typedef std::vector<int> subset;
typedef std::vector<subset> matrix;

void powerset(int arr[], int length)
{
  std::vector< std::vector<int> > result;
  int n = 1 << length;
  for (int i = 0; i < n; ++i)
    result.push_back(std::vector<int>());

  for (int i = 0; i < n; ++i) {
    //subset row;
    for (int j = 0; j < length; ++j) {
      if (i & (1 << j)) {
        //row.push_back(arr[j-1]);
        result[i].push_back(arr[j]);
      }
    }
    //result.push_back(row);
  }

  for (int i = 0; i < n; ++i) {
    for (std::vector<int>::const_iterator it = result[i].begin(); it != result[i].end(); ++it) {
      std::cout << *it << " ";
    }
    std::cout << std::endl;
  }
}

int main(int argc, char *argv[])
{
  int arr[] = {1, 2, 3};

  powerset(arr, sizeof(arr)/sizeof(*arr));
  return 0;
}
