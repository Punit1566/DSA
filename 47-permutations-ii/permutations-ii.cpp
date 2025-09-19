class Solution {
public:
    void solve(int id, vector<int>&nums, set<vector<int>>&st){
        if(id==nums.size()-1){
            st.insert(nums);
            return;
        }

        for(int i=id;i<nums.size();i++){
            swap(nums[i],nums[id]);
            solve(id+1,nums,st);
            swap(nums[i],nums[id]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>>st;
        solve(0, nums,st);
        vector<vector<int>>ans(st.begin(),st.end());
        return ans;
    }
};