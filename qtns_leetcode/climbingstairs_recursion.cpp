class Solution {
public:
int counting(int n){
    if(n==-1) return 0 ;
    if (n==0) return 1 ;
    return counting(n-1)+counting(n-2);
}
    int climbStairs(int n) {
        return counting(n);
    }
};