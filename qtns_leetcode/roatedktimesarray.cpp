class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // int n = nums.size();
        // int kf = k % n; // Calculate the effective rotation amount
        
        // // Temporary vector to store elements to be rotated
        // vector<int> temp(nums.begin() + (n - kf), nums.end());
        
        // // Shift elements to the right to make room for rotated elements
        // for(int i = n - 1; i >= kf; i--) {
        //     nums[i] = nums[i - kf];
        // }
        
        // // Copy rotated elements from temporary vector to the beginning of nums
        // for(int i = 0; i < kf; i++) {
        //     nums[i] = temp[i];
        // }


        //part 2 
int n = nums.size();
vector<int> ans(n);
for (int i = 0; i < n; i++) {
    int new_index = (i + k) % n; // Calculate the new index after rotation
    ans[new_index] = nums[i]; // Assign the element to the new index in the result vector
}
nums = ans; // Update nums with the rotated elements
    }
};
