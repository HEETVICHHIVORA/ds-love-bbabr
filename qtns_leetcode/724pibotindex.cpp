class Solution {
public:

    int pivotIndex(vector<int>& nums) {
       int n = nums.size();
       int i ;
       int leftsum = 0;
       int total = 0;
       for (i=0;i<n;i++){
         total+=nums[i];
       } 
       for(i=0;i<n;i++){
         int rightsum = total - leftsum -nums[i];
          if (leftsum==rightsum){
             return i;  
         }
         leftsum+=nums[i];
       }
       return -1;
    }
};