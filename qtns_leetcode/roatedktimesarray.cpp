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



// approach best 


class Solution {
public:
    // Function to reverse a subarray of nums from index low to high
    void reverse(vector<int> &nums, int low, int high) {
        while (low < high) {
            // Swap elements at low and high indices
            swap(nums[low], nums[high]);
            // Move low index forward and high index backward
            low++;
            high--;
        }
    }

    // Function to rotate the elements of nums to the right by k positions
    void rotate(vector<int>& nums, int k) {
        int n = nums.size(); // Get the size of the nums vector
        k%=n;
        // Step 1: Reverse the first n-k elements
        reverse(nums, 0, n - k - 1);

        // Step 2: Reverse the last k elements
        reverse(nums, n - k, n - 1);

        // Step 3: Reverse the entire array
        reverse(nums, 0, n - 1);
    }
};

