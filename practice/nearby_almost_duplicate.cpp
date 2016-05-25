#include<iostream>
#include<vector>
#include<set>

using namespace std; 


void print_set(set<int> &s)
{
   cout << "[ ";
   for (set<int>::const_iterator it = s.begin(); it != s.end(); ++it) {
       cout << *it << " ";
   }
   cout << " ]";
   cout << endl;
}

bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {

      set<int> window;

        for(int i=0; i<(int)nums.size(); ++i){

            if(i>k) {
            cout << "Before erase: " << endl;
            print_set(window);
            window.erase(nums[i-1-k]);
            cout << "After erase: " << endl;
            print_set(window);
            }

            set<int>::const_iterator p = window.lower_bound(nums[i]-t);

            if(p!=window.end() && *p-nums[i]<=t) {
              cout << "****** p =  " << *p << endl;
              print_set(window);
              cout << "****** nums[i] = " <<  nums[i] << endl;
              return true;
            }

            cout << "Before insert: " << endl;
            print_set(window);
            window.insert(nums[i]);
            cout << "After insert: " << endl;
            print_set(window);

        }

        return false;

    }

int main(void)
{
  int arr[] = {1, 5, 28, 12, 15, 34, 7, 55};
  vector<int> vec(arr, arr + sizeof(arr)/sizeof(arr[0])); 
  bool b = containsNearbyAlmostDuplicate(vec, 2, 3);
  cout << (b ? "true" : "false") << endl;
  return 0;
}
