class Solution {
public:
    int solve(int i,int j,vector<vector<int>>&grid){
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<int,int>>q;
        q.push({i,j});
        int ans=grid[i][j];
        vector<vector<int>>vis(m,vector<int>(n,0));
        vis[i][j]=1;
        vector<pair<int,int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(auto x:dir){
                int nrow=row+x.first;
                int ncol=col+x.second;
                if(nrow>=0 && nrow<m&&ncol>=0 && ncol<n && !vis[nrow][ncol] && grid[nrow][ncol]>0){
                    q.push({nrow,ncol});
                    ans+=grid[nrow][ncol];
                    vis[nrow][ncol]=1;
                }
            }
        }
        return ans;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]>0){
                    ans=max(ans,solve(i,j,grid));
                }
            }
        }
        return ans;
    }
};