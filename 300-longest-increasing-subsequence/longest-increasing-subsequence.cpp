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
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int curr=n-1;curr>=0;curr--){
            for(int prev=curr-1;prev>=-1;prev--){
                int a=dp[curr+1][prev+1];
                if(prev==-1||nums[curr]>nums[prev]){
                    a=max(a,1+dp[curr+1][curr+1]);
                }
                dp[curr][prev+1]=a;
            }
        }
        return dp[0][-1+1];

        // return solve(0,-1,nums,dp);
    }
};