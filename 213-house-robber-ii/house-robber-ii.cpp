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
        if(n==1)return nums[0];
        vector<int>dp(n,-1);
        int ans1=solve(1,nums,dp);
        vector<int>dp2(n,-1);
        vector<int>res=nums;res.pop_back();
        int ans2=solve(0,res,dp2);

        return max(ans1,ans2);
    }
};