/**
 * The idea is to fill all the valleys and then find out the water capacity.
 * For each height, find its left peak and right peak and substitute with the least of two
 * If either left or right peak is not found (no number on the right side is greater), then don't change the number
*/

class Solution {
    private:
    int get_peak_from_left(int i, vector<int>& height, int num) {
        while(i >= 0) {
            if (height[i] > num) {
                return height[i];
            }
            i--;
        }
        return num;
    }
    
    int get_peak_from_right(int i, vector<int>& height, int num) {
        while(i < height.size()) {
            if (height[i] > num) {
                return height[i];
            }
            i++;
        }
        return num;
    }
    
    bool perfect_mountain(vector<int>& height, int peakIndex) {
        // Everything on the left of peak should be less than peak
        // and everything on the right of peak should be less than peak too.
        int i = peakIndex-1;
        while (i>=0) {
            if (height[i] > height[i+1]) {
                return false;
            }
            i--;
        }
        
        i = peakIndex+1;
        while (i<height.size()) {
            if (height[i] > height[i+1]) {
                return false;
            }
            i++;
        }
        
        return true;
    }
    
public:
    void print_vec(vector<int>& vec) {
        for (int i = 0; i < vec.size(); ++i) {
            cout << vec[i] << " ";
        }
        cout << endl;
    }
    
    int trap(vector<int>& height) {
        vector<int> orig(height);
        
        int peak = INT_MIN;
        int peakIndex = -1;
        for (int i = 0; i < height.size(); ++i) {
            if (height[i] > peak) {
                peak = height[i];
                peakIndex = i;
            }
        }
        
        do {
            for (int i = 1; i < height.size()-1; ++i) {
                int leftPeak  = get_peak_from_left(i-1, height, height[i]);
                int rightPeak = get_peak_from_right(i+1, height, height[i]);
                height[i] = min(leftPeak, rightPeak);
            }
        } while (!perfect_mountain(height, peakIndex));
        
        print_vec(orig);
        print_vec(height);
        
        int capacity = 0;
        for (int i = 0; i < height.size(); ++i) {
            capacity += abs(height[i] - orig[i]);
        }
        
        return capacity;
    }
};
