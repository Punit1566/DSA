class NumMatrix {
public:
    int m,n;
    vector<vector<int>>dp;
    NumMatrix(vector<vector<int>>& matrix) {
        m=matrix.size();
        n=matrix[0].size();
        vector<vector<int>>dp1(m,vector<int>(n));
        dp1[0][0]=matrix[0][0];
        for(int row=1;row<m;row++){
            dp1[row][0]=dp1[row-1][0]+matrix[row][0];
        }
        for(int col=1;col<n;col++){
            dp1[0][col]=dp1[0][col-1]+matrix[0][col];
        }
        for(int row=1;row<m;row++){
            for(int col=1;col<n;col++){
                dp1[row][col]=matrix[row][col]+dp1[row-1][col]+dp1[row][col-1]-dp1[row-1][col-1];
            }
        }
        dp=dp1;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return dp[row2][col2]-((row1>0)?dp[row1-1][col2]:0) - ((col1>0)?dp[row2][col1-1]:0)
        +((row1>0&&col1>0)?dp[row1-1][col1-1]:0);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */