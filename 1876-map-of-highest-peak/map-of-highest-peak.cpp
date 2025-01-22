class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        queue<pair<int,pair<int,int>>>q;
        int m=isWater.size();
        int n=isWater[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(isWater[i][j]==1){
                    q.push({0,{i,j}});
                    vis[i][j]=1;
                    isWater[i][j]=0;
                }else{
                    isWater[i][j]=1;
                }
            }
        }
        vector<pair<int,int>>nbr={{0,-1},{0,1},{1,0},{-1,0}};
        while(!q.empty()){
            int val=q.front().first;
            int row=q.front().second.first;
            int col=q.front().second.second;
            q.pop();
            for(auto x:nbr){
                int nrow=row+x.first;
                int ncol=col+x.second;
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n &&!vis[nrow][ncol]){
                    isWater[nrow][ncol]=val+1;
                    vis[nrow][ncol]=1;
                    q.push({val+1,{nrow,ncol}});
                }
            }
        }
        return isWater;
    }
};