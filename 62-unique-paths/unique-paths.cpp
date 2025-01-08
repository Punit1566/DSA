class Solution {
public:
    int solve(int i,int j,int &m,int &n,vector<vector<int>>&dp){
        if(i==m-1&&j==n-1)return 1;

        if(dp[i][j]!=-1)return dp[i][j];
        int temp1=0;
        if(i+1<m){
            temp1=solve(i+1,j,m,n,dp);
        }
        int temp2=0;
        if(j+1<n){
            temp2=solve(i,j+1,m,n,dp);
        }

        return dp[i][j]=temp1+temp2;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return solve(0,0,m,n,dp);
    }
};