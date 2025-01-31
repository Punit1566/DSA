class Solution {
public:
    bool isBipartite(int curr_node,unordered_map<int,vector<int>>&adj,vector<int>&colors,
    int curr_color){
        colors[curr_node]=curr_color;
        for(int &nbr:adj[curr_node]){
            if(colors[nbr]==colors[curr_node]){
                return false;
            }
            if(colors[nbr]==-1){
                if(!isBipartite(nbr,adj,colors,1-curr_color)){
                    return false;
                }
            }
        }
        return true;
    }
    int bfs(unordered_map<int,vector<int>>&adj,int node,int &n){
        queue<int>q;
        vector<int>vis(n,0);
        q.push(node);
        vis[node]=true;
        int level=0;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                int curr=q.front();
                q.pop();
                for(int nbr:adj[curr]){
                    if(vis[nbr])continue;

                    q.push(nbr);
                    vis[nbr]=1;
                }
            }
            level++;
        }
        return level;
    }
    int getMaxfromEachComp(unordered_map<int,vector<int>>&adj,int curr,vector<int>&vis,vector<int>&levels){
        int max_group=levels[curr];
        vis[curr]=1;
        for(int &nbr:adj[curr]){
            if(!vis[nbr]){
                max_group=max(max_group,getMaxfromEachComp(adj,nbr,vis,levels));
            }
        }
        return max_group;
    }
    int magnificentSets(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>>adj;
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0]-1;
            int v=edges[i][1]-1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        //Bipartite Check
        vector<int>colors(n,-1);
        for(int node=0;node<n;node++){
            if(colors[node]==-1){
                if(!isBipartite(node,adj,colors,1)){
                    return -1;
                }
            }
        }
        //calculating max_depth
        vector<int>levels(n,0);
        for(int node=0;node<n;node++){
            levels[node]=bfs(adj,node,n);
        }

        int ans=0;
        vector<int>vis(n,0);
        for(int node=0;node<n;node++){
            if(!vis[node]){
                ans+=getMaxfromEachComp(adj,node,vis,levels);
            }
        }
        return ans;
    }
};