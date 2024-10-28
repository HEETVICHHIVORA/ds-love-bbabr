class Solution {
public:
    int solvefirst(int i,vector<int>nums,vector<int>& dp1){
        if(i>=nums.size()-1) return 0;
        if(dp1[i]!=-1) return dp1[i];
        return dp1[i] = max(nums[i]+solvefirst(i+2,nums,dp1),solvefirst(i+1,nums,dp1));
    }
    int solvesec(int i,vector<int> nums,vector<int>&dp2){
        if(i>=nums.size()) return 0 ;
        if(dp2[i]!=-1) return dp2[i];
        return dp2[i] = max(nums[i]+solvesec(i+2,nums,dp2),solvesec(i+1,nums,dp2));
    }
    int rob(vector<int>& nums) {
        vector<int>dp1(nums.size()+1,-1);
        vector<int>dp2(nums.size()+1,-1);
        if(nums.size()==1) return nums[0];
        return max(solvefirst(0,nums,dp1),solvesec(1,nums,dp2));
    }
};