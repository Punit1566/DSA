class Solution {
public:
    bool check(int row, int col, vector<string>&temp){
        int n=temp.size();

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(temp[i][j]=='Q'){
                    if(i==row || j== col){
                        return false;
                    }
                    else if(i+j==row+col||row-col==i-j){
                        return false;
                    }
                }
                
            }
        }
        return true;

    }
    void solve(int i, int j,int cnt,vector<string>&temp,vector<vector<string>>&ans){
        //base case
        if(cnt==temp.size()){
            ans.push_back(temp);
            return;
        }
        if(i==temp.size()){
            return;
        }
        if(j == temp.size()){
            solve(i+1, 0, cnt, temp, ans);
            return;
        }
        //check whether possible or not
        if(check(i,j,temp)){
            temp[i][j]='Q';
            solve(i,j+1,cnt+1,temp,ans);
            temp[i][j]='.';
        }
        solve(i,j+1,cnt,temp,ans);
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>temp;
        for(int i=0;i<n;i++){
            string t;
            for(int j=0;j<n;j++){
                t+='.';
            }
            temp.push_back(t);
        }

        solve(0,0,0,temp,ans);
        return ans;
    }
};