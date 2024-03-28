class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int i =0,j=n-1;
        int it = 0;

        while(it<=j){
            if(nums[it]==0){
                swap(nums[it],nums[i]);
                i++;
                it++;

            }
           else if(nums[it]==2){
                swap(nums[j],nums[it]);
                j--;
            }
            else   it++;
           

        }
    }
};


// right wale case me index ko aage nai badane hai mistake hai wo badi 