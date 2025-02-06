class DisjointSetUnion{
    vector<int>parent,rank;
    public:
    DisjointSetUnion(int n){
        rank.resize(n,0);
        parent.resize(n,0);
        iota(parent.begin(),parent.end(),0);
    }
    int findUParent(int n){
        if(n==parent[n])return n;
        return findUParent(parent[n]);
    }
    void UnionByRank(int u,int v){
        int ulp_u=findUParent(u);
        int ulp_v=findUParent(v);

        if(ulp_u==ulp_v)return;
        if(rank[ulp_u]>rank[ulp_v]){
            parent[ulp_v]=ulp_u;
        }else if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u]=ulp_v;
        }else{
            parent[ulp_u]=ulp_v;
            rank[ulp_u]++;
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        DisjointSetUnion d(n);
        unordered_map<string,int>mp;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string x=accounts[i][j];
                if(mp.find(x)==mp.end()){
                    mp[x]=i;
                }else{
                    d.UnionByRank(i,mp[x]);
                }
            }
        }
        unordered_map<int,vector<string>>mp2;
        for(auto x:mp){
            int ulp_x=d.findUParent(x.second);
            mp2[ulp_x].push_back(x.first);
        }
        vector<vector<string>>ans;
        for(auto x:mp2){
            vector<string>temp;
            temp.push_back(accounts[x.first][0]);
            for(auto str:x.second){
                temp.push_back(str);
            }
            sort(temp.begin()+1,temp.end());
            ans.push_back(temp);
        }
        return ans;
    }
};