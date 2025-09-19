class Solution {
public:
    void solve(int &n,int open, int close, string &temp,vector<string>&ans){
        if(open==n&&close==n){
            ans.push_back(temp);
            return;
        }

        if(open==close){
            temp+='(';
            solve(n,open+1,close,temp,ans);
            temp.pop_back();
        }else if(open>close){
            temp.push_back(')');
            solve(n,open,close+1,temp,ans);
            temp.pop_back();

            if(open<n){
                temp+='(';
                solve(n, open+1,close,temp,ans);
                temp.pop_back();
            }
        }
    }
    vector<string> generateParenthesis(int n) {
        int open=0,close=0;
        vector<string>ans;
        string temp="";
        solve(n, open,close, temp,ans);
        return ans;
    }
};