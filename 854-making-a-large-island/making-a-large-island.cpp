class Solution {
public:
    void solve(int i,int j,vector<vector<int>>& grid,vector<vector<int>>&vis,
    unordered_map<int,int>&unq_id,int curr_id){
        int n=grid.size();
        queue<pair<int,int>>q;
        q.push({i,j});
        vis[i][j]=1;
        vector<pair<int,int>>used;
        used.push_back({i,j});
        vector<pair<int,int>>nbr={{0,-1},{0,1},{-1,0},{1,0}};
        int sz=1;
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(auto &x:nbr){
                int nrow=row+x.first;
                int ncol=col+x.second;
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && grid[nrow][ncol]==1&&vis[nrow][ncol]==0){
                    q.push({nrow,ncol});
                    vis[nrow][ncol]=1;
                    sz++;
                    used.push_back({nrow,ncol});
                }
            }
        }
        for(auto x:used){
            vis[x.first][x.second]=curr_id;
        }
        unq_id[curr_id]=sz;
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        // vector<vector<int>>updated(n,vector<int>(n,0));
        unordered_map<int,int>unq_id;
        vector<vector<int>>vis(n,vector<int>(n,0));
        int curr_id=2;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1&&vis[i][j]==0){
                    solve(i,j,grid,vis,unq_id,curr_id);
                    curr_id++;
                }
            }
        }
        
        int maxi=0;
        vector<pair<int,int>>nbr={{-1,0},{1,0},{0,-1},{0,1}};
        // int left_down,down_right,right_up,up_left;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    int ans=0;
                    unordered_set<int>st;
                    for(auto x:nbr){
                        int row=i+x.first;
                        int col=j+x.second;
                        if(row>=0 && row<n && col>=0 && col<n && grid[row][col]==1){
                            int id=vis[row][col];
                            if(st.find(id)==st.end()){
                                ans+=unq_id[id];
                                st.insert(id);
                            }
                        }
                    }
                    maxi=max(maxi,ans);
                }
            }
        }
        if(maxi==0){
            if(grid[0][0]==1)return n*n;
        }
        return maxi+1;
        
    }
};