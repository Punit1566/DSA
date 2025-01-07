class Solution {
public:
    int solve(int i,vector<int>&nums,vector<int>&dp){
        if(i>=nums.size())return 0;

        if(dp[i]!=-1)return dp[i];
        int temp1=solve(i+2,nums,dp)+nums[i];
        int temp2=solve(i+1,nums,dp)+0;
        return dp[i]=max(temp1,temp2);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        // if(n==2)return max(nums[0],nums[1]);
        vector<int>dp(n+1,-1);
        return solve(0,nums,dp);
    }
};