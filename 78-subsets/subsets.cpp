class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans;
        for(int i=0;i<(1<<n);i++){
            vector<int>temp;
            int t=i;
            int j=0;
            while(t>>j){
                if((1&(t>>j))) temp.push_back(nums[j]);
                j++;
            }
            ans.push_back(temp);
        }
        return ans;
    }
};