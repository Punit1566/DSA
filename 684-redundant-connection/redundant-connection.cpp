class Solution {
public:
    bool dfs(int src,int &dest,unordered_map<int,vector<int>>&adjList,vector<int>&visited){
        if(src==dest){
            return true;
        }
        visited[src]=1;
        for(auto x:adjList[src]){
            if(!visited[x]){
                if(dfs(x,dest,adjList,visited))return true;
            }
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int>vis(n+1,0);
        unordered_map<int,vector<int>>adjList;
        for(auto x:edges){
            int u=x[0];
            int v=x[1];
            if(!vis[u]||!vis[v]){
                adjList[u].push_back(v);
                adjList[v].push_back(u);
                vis[u]=1;vis[v]=1;
            }else{
                vector<int>visited(n+1,0);
                bool ans=dfs(u,v,adjList,visited);
                if(!ans){
                    adjList[u].push_back(v);
                    adjList[v].push_back(u);
                    vis[u]=1;vis[v]=1;
                }else{
                    return {u,v};
                }
            }
        }
        return {-1,-1};

    }
};