class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j  =0;
        int i = 1;
           int count =0 ;
        while(i<nums.size()){
            if(nums[i]==nums[j]) i++;
            else {
                count++;
                nums[++j]=nums[i++];
            }
        }
        return count+1; 
    }
};