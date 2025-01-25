class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n=nums.size();
        vector<int>temp(nums.begin(),nums.end());
        sort(temp.begin(),temp.end());

        int idx=0;
        unordered_map<int,queue<int>>mp;
        mp[idx].push(temp[0]);
        unordered_map<int,int>check;
        check[temp[0]]=idx;
        for(int i=1;i<n;i++){
            if(temp[i]-temp[i-1]<=limit){
                mp[idx].push(temp[i]);
            }else{
                idx++;
                mp[idx].push(temp[i]);
            }
            check[temp[i]]=idx;
        }
        for(int i=0;i<n;i++){
            int find_set=check[nums[i]];
            nums[i]=mp[find_set].front();
            mp[find_set].pop();
        }
        return nums;
    }
};