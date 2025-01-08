class Solution {
public:
    int solve(int i,int j,int &m,int &n,vector<vector<int>>&grid,vector<vector<int>>&dp){
        
        if(i==m-1&&j==n-1){
            return grid[i][j];
        }
        if(dp[i][j]!=-1)return dp[i][j];
        int right=INT_MAX;
        if(j+1<n){
            right=grid[i][j]+solve(i,j+1,m,n,grid,dp);
        }
        int down=INT_MAX;
        if(i+1<m){
            down=grid[i][j]+solve(i+1,j,m,n,grid,dp);
        }

        return dp[i][j]=min(right,down);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return solve(0,0,m,n,grid,dp);
    }
};