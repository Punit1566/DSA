class Solution {
public:
    int solve(int idx1,int idx2,string &txt1,string &txt2,vector<vector<int>>&dp){
        if(idx1==txt1.size()||idx2==txt2.size())return 0;
        int matches=INT_MIN;
        int not_matches=INT_MIN;
        if(dp[idx1][idx2]!=-1)return dp[idx1][idx2];
        if(txt1[idx1]==txt2[idx2]){
            matches=1+solve(idx1+1,idx2+1,txt1,txt2,dp);
        }else{
            not_matches=max(solve(idx1+1,idx2,txt1,txt2,dp),solve(idx1,idx2+1,txt1,txt2,dp));
        }
        return dp[idx1][idx2]=max(matches,not_matches);
    }
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size();
        int n=text2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1));
        for(int i=0;i<=n;i++)dp[0][i]=0;
        for(int i=0;i<=m;i++)dp[i][0]=0;

        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
        // return solve(0,0,text1,text2,dp);
    }
};