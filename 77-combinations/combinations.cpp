class Solution {
public:
    void solve(int &n,int i, int &k,int taken, vector<int>&temp,vector<vector<int>>&ans){

        if(taken==k){
            ans.push_back(temp);
            return;
        }
        if(i>n){
            return;
        }

        for(int id=i;id<=n;id++){
            temp.push_back(id);
            taken++;
            solve(n,id+1,k,taken,temp,ans);
            temp.pop_back();
            taken--;
        }

    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>temp;
        int taken=0;
        solve(n,1,k,taken,temp,ans);
        return ans;
    }
};