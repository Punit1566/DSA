class Solution {
public:
    int solve(int &i,int &j,vector<vector<int>>& grid, vector<vector<int>>&vis){
        int m=grid.size();int n=grid[0].size();
        queue<pair<int,int>>q;
        q.push({i,j});
        vis[i][j]=1;
        vector<pair<int,int>>nbr={{0,-1},{0,1},{-1,0},{1,0}};
        int sz=1;
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(auto x:nbr){
                int nrow=row+x.first;
                int ncol=col+x.second;
                if(nrow>=0 &&nrow<m && ncol>=0 &&ncol<n &&grid[nrow][ncol]==1&&!vis[nrow][ncol]){
                    q.push({nrow,ncol});
                    vis[nrow][ncol]=1;
                    sz++;
                }
            }

        }
        return sz;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxi=0;
        int m=grid.size();int n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    maxi=max(maxi,solve(i,j,grid,vis));
                }
            }
        }

        return maxi;
    }
};