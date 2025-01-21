class Solution {
public:
    int solve(int curr,int prev,vector<int>&nums,vector<vector<int>>&dp){
        if(curr==nums.size())return 0;
        if(dp[curr][prev+1]!=-1)return dp[curr][prev+1];
        int a=solve(curr+1,prev,nums,dp);
        int b=0;
        if(prev==-1||nums[curr]>nums[prev]){
            b=1+solve(curr+1,curr,nums,dp);
        }
        return dp[curr][prev+1]=max(a,b);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return solve(0,-1,nums,dp);
    }
};