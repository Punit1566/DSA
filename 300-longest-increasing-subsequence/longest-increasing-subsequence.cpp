class Solution {
public:
    int solve(int curr,int i,vector<int>&nums,vector<vector<int>>&dp){
        if(i==nums.size())return 0;
        if(dp[i][curr+1]!=-1)return dp[i][curr+1];
        int t1=INT_MIN,t2=INT_MIN;
        t2=solve(curr,i+1,nums,dp);
        if(curr==-1||nums[i]>nums[curr]){
            t1= 1+solve(i,i+1,nums,dp);
        }
        return dp[i][curr+1]=max(t1,t2);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return solve(-1,0,nums,dp);
    }
};