class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int,vector<pair<int,int>>>adj;
        for(auto x:roads){
            adj[x[0]].push_back({x[1],x[2]});
            adj[x[1]].push_back({x[0],x[2]});
        }
        queue<pair<int,int>>q;
        int ans=INT_MAX;
        q.push({1,INT_MAX});
        vector<int>vis(n+1,0);
        vis[1]=1;
        while(!q.empty()){
            int node=q.front().first;
            int weight=q.front().second;
            vis[node]=true;
            ans=min(ans,weight);
            q.pop();
            for(auto &nbr:adj[node]){
                if(!vis[nbr.first]){
                    q.push(nbr);
                }
            }
        }
        return ans;

    }
};