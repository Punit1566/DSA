class Solution {
public:
    bool isPal(string& s, int i, int j,vector<vector<bool>>&dp){
        if(i>=j){
            return dp[i][j]=true;
        }
        if(dp[i][j]){
            return true;
        }
        if(s[i]==s[j]){
            return dp[i][j]=isPal(s,i+1,j-1,dp);
        }else{
            return dp[i][j]=false;
        }
    }
    string longestPalindrome(string s) {
        int n=s.length();
        int maxLength=0;
        int start=-1;
        vector<vector<bool>>dp(n+1,vector<bool>(n+1,false));
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(isPal(s,i,j,dp)){
                    if(maxLength<j-i+1){
                        maxLength=j-i+1;
                        start=i;
                    }
                }
            }
        }
        return s.substr(start,maxLength);
    }
};