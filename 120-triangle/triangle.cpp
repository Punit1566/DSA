class Solution {
public:
    int solve(int i,int j,int &row,vector<vector<int>>&triangle, vector<vector<int>>&dp){
        if(i==row-1)return triangle[i][j];
        if(dp[i][j]!=-1)return dp[i][j];
        int down=INT_MAX;
        if(i<row){
            down=triangle[i][j]+solve(i+1,j,row,triangle,dp);
        }
        int down_right=INT_MAX;
        if(j<row){
            down_right=triangle[i][j]+solve(i+1,j+1,row,triangle,dp);
        }
        return dp[i][j]=min(down,down_right);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int row=triangle.size();
        vector<vector<int>>dp(row+1,vector<int>(row+1,-1));
        return solve(0,0,row,triangle,dp);
    }
};