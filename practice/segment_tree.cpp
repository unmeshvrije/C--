#include<iostream>
#include<vector>
#include<queue>
#include<sstream>
#include<cmath>
#include<cassert>

using namespace std;

class NumArray {
    
    private:
    struct TreeNode {
        int val;
        int start;
        int end;
        TreeNode(int v, int s, int e): val(v), start(s), end(e){}
        TreeNode(){}
    };
    
    int n;
    vector<int> nums;
    vector<int> orig;
    TreeNode *tree;
    
    int get_sum(int i, int j, int k) {

      if (k >= n*4) {
        return 0;
      }

      TreeNode root = tree[k];

      if (i <= root.start && root.end <= j) {
        return root.val;
      }

      return get_sum(i,j, 2*k) + get_sum(i,j,2*k +1);
    }
public:

    NumArray(vector<int> &nums) {
        this->nums = vector<int>(nums);
        n = (int)nums.size();

        tree = new TreeNode[4*n];

        build_tree(1, 0, n-1);
    }
 
    void build_tree(int k, int start, int end) {
      if (start == end) {
        tree[k].val = nums[start];
        tree[k].start = start;
        tree[k].end = end;
      } else {
        int mid = floor((start + end) /2);
        build_tree(2*k, start, mid);
        build_tree(2*k + 1, mid+1, end);
        tree[k].val = tree[2*k].val + tree[2*k+1].val;
        tree[k].start = tree[2*k].start;
        tree[k].end = tree[2*k+1].end;
      }
    }

    void print_tree() {
        for (int i = 1; i < 4*n; ++i) {
          cout << "["<< i << "] " << tree[i].val << "(" << tree[i].start << "," << tree[i].end << ")" << endl;
        }
    }
    
    void update(int i, int val) {
        int old = nums[i];
        int delta = val - old;
        nums[i] = val;
        cout << "delta : " << delta << endl;
        int k = 1;//root
        while(k < 4*n) {
            TreeNode& temp = tree[k];
            if (temp.start <= i && i <= temp.end) {
              //cout << "HEREEEEEEEEEEE" << endl;
                temp.val += delta;
            }
            int mid = (temp.start + temp.end) / 2;
            if (i <= mid) {
                k = 2*k;
            } else {
                k = 2*k + 1;
            }
        }
    }

    int sumRange(int i, int j) {
        // sumRange(1,3)
       return get_sum(i, j, 1);
    }
};

string print_array(vector<int>&nums, int i, int j)
{
    stringstream ss;
    for (int k = i; k <=j; ++k) {
        ss << nums[k];
        if (k+1 <= j) {
            ss << "+";
        }
    }
    
    ss << " = ";
    return ss.str();
}

int main()
{
    int arr[] = {-28,-39,53,65,11,-56,-65,-39,-43,97};
    vector<int> nums (arr, arr + sizeof(arr)/sizeof(*arr));
    NumArray num_array (nums);
    num_array.print_tree();
    cout << endl;
    return 0;
    
    num_array.update(4,6);
    nums[4]= 6;
    num_array.print_tree();
    cout << "XXXXXXXXXXXXX" << endl;

    num_array.update(0,2);
    nums[0] = 2;
    num_array.print_tree();
    cout << "XXXXXXXXXXXXX" << endl;

    num_array.update(0,9);
    nums[0]=9;
    num_array.print_tree();
    cout << "XXXXXXXXXXXXX" << endl;

    cout << print_array(nums, 4,4) << num_array.sumRange(4,4) << endl;

    num_array.update(3,8);
    nums[3] = 8;
    num_array.print_tree();
    cout << "XXXXXXXXXXXXX" << endl;

    cout << print_array(nums, 0,4) << num_array.sumRange(0,4) << endl;
    return 0;
}
