class Solution {
public:
    bool check(int &row,int &col, vector<string>&board){
        int n=(int)board.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='Q'){

                    if(i==row || j==col) return false;

                    if(i+j==row+col ||i-j==row-col) return false;
                }
            }
        }
        return true;
    }
    void solve(int &n, int row, vector<string>&board,int &cnt){
        if(row==n){
            cnt++;
            return;
        }
        for(int col=0;col<n;col++){
            if(check(row,col,board)){
                board[row][col]='Q';
                solve(n,row+1,board,cnt);
                board[row][col]='.';
            }
        }
    }
    int totalNQueens(int n) {
        vector<string>board(n,string(n,'.'));
        int cnt=0;
        solve(n,0,board,cnt);
        return cnt;
    }
};