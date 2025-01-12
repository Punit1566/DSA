class Solution {
public:
    bool solve(int i,int sum,vector<int>&nums,vector<vector<int>>&dp){
        if(i>=nums.size())return false;
        if(sum==0)return true;
        if(dp[i][sum]!=-1)return dp[i][sum];
        if(sum>=nums[i]){
            return dp[i][sum]=solve(i+1,sum-nums[i],nums,dp)||solve(i+1,sum,nums,dp);
        }else{
            return dp[i][sum]=solve(i+1,sum,nums,dp);
        }
    }
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%2==1)return false;
        sum/=2;
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        return solve(0,sum,nums,dp);
    }
};