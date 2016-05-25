#include<iostream>
#include<vector>
using namespace std;

int max_helper(int,int,int,vector<int>&,int);

int find_max_sum(vector<int>& nums)
{
  if (nums.size() == 0){
    return 0;
  }

  if (nums.size() == 1) {
    return nums[0];
  }

  if (nums.size() == 2) {
    return max(nums[0], nums[1]);
  }

  vector<int> max(nums.size());
  max[0] = nums[0];
  max[1] = nums[1];
  max[2] = nums[2] + nums[0];

//  return max_helper(max[0], max[1], max[2], nums, 3);
  
  int i;
  for (i = 3; i < nums.size(); ++i) {
    max[i] = nums[i] + ::max(max[i-2], max[i-3]);
  }

  return ::max(max[i-1], max[i-2]);
}

int max_helper(int max_i_3, int max_i_2, int max_i_1, vector<int> &nums, int index) {
  if (index >= nums.size()) {
    return ::max(max_i_1, max_i_2);
  }
  return max_helper(max_i_2, max_i_1, ::max(max_i_3, max_i_2) + nums[index], nums, index+1);
}

int main(int argc, char *argv[])
{
  int arr[] =  {5, 23, 15, 8, 12, 6, 10, 19};
  vector<int> nums(arr, arr + sizeof(arr) / sizeof(arr[0]));

  for (int i = 0; i < nums.size(); ++i) {
    cout << nums[i] << " ";
  }
  cout << endl;
  cout << find_max_sum(nums) << endl;;
  return 0;
}
