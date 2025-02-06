class DSU{
    public:
    vector<int>parent,size;
    DSU(int n){
        size.resize(n,1);
        parent.resize(n);
        iota(parent.begin(),parent.end(),0);
    }
    int findUParent(int n){
        if(parent[n]==n)return n;
        return parent[n]=findUParent(parent[n]);
    }
    void UnionBySize(int u,int v){
        int ulp_u=findUParent(u);
        int ulp_v=findUParent(v);

        if(ulp_u==ulp_v)return;

        if(size[ulp_u]>size[ulp_v]){
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }else if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }else{
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};

class Solution {
public:
    bool isValid(int n,int row,int col){
        return row>=0 && row<n && col>=0 && col<n;
    }
    void BFS(int i,int j,vector<vector<int>>& grid,vector<vector<int>>&vis, DSU &d){
        queue<pair<int,int>>q;
        int n=grid.size();
        q.push({i,j});
        vis[i][j]=1;
        vector<pair<int,int>>nbr={{0,-1},{0,1},{-1,0},{1,0}};
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(auto &x:nbr){
                int nrow=row+x.first;
                int ncol=col+x.second;
                if(isValid(n,nrow,ncol) && grid[nrow][ncol]==1 && !vis[nrow][ncol]){
                    q.push({nrow,ncol});
                    vis[nrow][ncol]=1;
                    int u=row*n+col;
                    int v=nrow*n+ncol;
                    d.UnionBySize(u,v);
                }
            }
        }
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        DSU d(n*n);
        vector<vector<int>>vis(n,vector<int>(n,0));
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==1&&!vis[row][col]){
                    BFS(row,col,grid,vis,d);
                }
            }
        }
        int maxi=0;
        vector<pair<int,int>>nbr={{0,-1},{0,1},{-1,0},{1,0}};
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==0){
                    unordered_set<int>st;
                    int ans=0;
                    for(auto &x:nbr){
                        int nrow=row+x.first;
                        int ncol=col+x.second;
                        if(isValid(n,nrow,ncol)&&grid[nrow][ncol]==1){
                            int idx=nrow*n+ncol;
                            int ulp_idx=d.findUParent(idx);
                            if(st.find(ulp_idx)==st.end()){
                                ans+=d.size[ulp_idx];
                                st.insert(ulp_idx);
                            }
                        }
                    }
                    maxi=max(maxi,ans+1);
                }
            }
        }
        if(maxi==0)return n*n;
        return maxi;
    }
};