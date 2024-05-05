class Solution {
public:
    int solve(string &w1,string &w2,int i ,int j, vector<vector<int>>&dp){
        if(i>=w1.size()){
           return w2.length()-j;
        }
        if(j>=w2.size()){
            return w1.length()-i; 
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans =0 ;
        if(w1[i]==w2[j]){
            ans=solve(w1,w2,i+1,j+1,dp);
        }
        else{
            int in = 1+solve(w1,w2,i,j+1,dp);
            int del = 1+solve(w1,w2,i+1,j,dp);
            int replace = 1+solve(w1,w2,i+1,j+1,dp);
            ans =  min(in,min(replace,del));
        }
        return dp[i][j] = ans ;
    }
    int minDistance(string word1, string word2) {
        int i =0 ;
        int j =0 ;
          vector<vector<int>>dp(word1.size() + 1 ,vector<int>(word2.size()+1,-1));
        return solve(word1,word2,i,j,dp);
    }
};