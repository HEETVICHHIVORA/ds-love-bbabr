class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        int kf = k % n; // Calculate the effective rotation amount
        
        // Temporary vector to store elements to be rotated
        vector<int> temp(nums.begin() + (n - kf), nums.end());
        
        // Shift elements to the right to make room for rotated elements
        for(int i = n - 1; i >= kf; i--) {
            nums[i] = nums[i - kf];
        }
        
        // Copy rotated elements from temporary vector to the beginning of nums
        for(int i = 0; i < kf; i++) {
            nums[i] = temp[i];
        }
    }
};
