class Solution {
public:

    long long gridGame(vector<vector<int>>& grid) {
        int col=grid[0].size();
        vector<vector<long long>>g(2,vector<long long>(col,0));
        for(int i=0;i<2;i++){
            g[i][0]=grid[i][0];
            for(int j=1;j<col;j++){
                g[i][j]=g[i][j-1]+grid[i][j];
            }
        }
        long long ans=1e11 ;
        for(int i=0;i<col;i++){
            //if it goes down from col 0;
            //left for rob 2 = g[0][col-1]-g[0][0]
            if(i==0){
                long long temp=g[0][col-1]-g[0][i];
                ans=min(ans,temp);
            }

            //if it goes down at any col except 0 and col-1
            //left for rob 2 = max(g[1][i-1],g[0][col-1]-g[0][i])
            else if(i!=0&&i!=col-1){
                long long temp=max(g[1][i-1],g[0][col-1]-g[0][i]);
                ans=min(ans,temp);
            }


            //if it goes down from col-1
            //left for rob 2= g[1][col-2]
            else{
                ans=min(ans,(long long)g[1][col-2]);
            }
        }
        return ans;
    }
};