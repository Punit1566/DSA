class Solution {
public:
    void solve(int i,vector<int>&nums,vector<int>&res,vector<vector<int>>&ans){
        if(i==nums.size()){
            ans.push_back(res);
            return;
        }
        res.push_back(nums[i]);
        solve(i+1,nums,res,ans);
        res.pop_back();
        solve(i+1,nums,res,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        // vector<vector<int>>ans;
        // vector<int>res;
        // solve(0,nums,res,ans);
        // return ans;
        int n=nums.size();
        vector<vector<int>>ans;
        for(int i=0;i<(1<<n);i++){
            vector<int>temp;
            for(int j=0;j<n;j++){
                // if(i&(1<<j)!=0) temp.push_back(nums[j]);// it answers wrong
                if(i&(1<<j)) temp.push_back(nums[j]);//runs well why?
                
            }
            ans.push_back(temp);
        }
        return ans;
    }
};