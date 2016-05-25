#include<iostream>
#include<vector>
using namespace std;



class NumArray {

    private:

    vector<int> nums;
    vector<int> sums;

    void print_vector(vector<int>& vec) {
      for (int i = 0; i < vec.size(); ++i) {
        cout << vec[i];
        if (i+1 < vec.size()) {
            cout << ", ";
        }
      }
      cout << endl;
    }

public:

    void print_nums() {
        print_vector(nums);
    }

    void print_sums() {
        print_vector(sums);
    }

    NumArray(vector<int> &nums) {
        // Copy all numbers
        this->nums = vector<int>(nums.size());
        this->sums = vector<int>(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            cout << i << endl;
            this->nums[i] = nums[i];
        }

        cout << "copied all" << endl;
        // Populate sums cache
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            cout << i << endl;
            sum += nums[i];
            sums[i] = sum;
        }
    }



    void update(int i, int val) {

        nums[i] = val;
        int sum = nums[i];

        if (i) {
            sum += sums[i-1];
        }
        sums[i] = sum;
        for (int j = i+1; j < sums.size(); ++j) {
            sum += nums[j];
            sums[j] = sum;
        }
    }



    int sumRange(int i, int j) {
        if (i < 0 || j < 0 || i > nums.size() || j > nums.size()) {
            return 0;
        }
        if (i == 0) {
            return sums[j];
        }
        return sums[j] - sums[i-1];
    }
};





// Your NumArray object will be instantiated and called as such:
int main()
{
 int arr[] = {1,3,5};

 vector<int> nums(arr, arr + sizeof(arr)/sizeof(*arr));
 NumArray numArray(nums);
 
 cout << "Init:" << endl;
 cout << "nums: "; numArray.print_nums();
 cout << "sums: "; numArray.print_sums();

 numArray.sumRange(0, 1);

 cout << "After update:" << endl;
 numArray.update(1, 10);
 cout << "nums: "; numArray.print_nums();
 cout << "sums: "; numArray.print_sums();

 numArray.sumRange(1, 2);
 return 0;
}
