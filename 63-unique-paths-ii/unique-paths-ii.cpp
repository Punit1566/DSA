class Solution {
public:
    int solve(int i,int j,int &m,int &n,vector<vector<int>>& arr,vector<vector<int>>&dp){
        if(i==m-1&&j==n-1){
            if(arr[i][j]==0){
                return 1;
            }else{
                return 0;
            }
        }
        if(arr[i][j]==1)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int right=0;
        if(j+1<n){
            if(arr[i][j+1]==0){
                right=solve(i,j+1,m,n,arr,dp);
            }
        }
        int down=0;
        if(i+1<m){
            if(arr[i+1][j]==0){
                down=solve(i+1,j,m,n,arr,dp);
            }
        }
        return dp[i][j]=right+down;

    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row=obstacleGrid.size();
        int col=obstacleGrid[0].size();
        vector<vector<int>>dp(row+1,vector<int>(col+1,-1));
        return solve(0,0,row,col,obstacleGrid,dp);
    }
};