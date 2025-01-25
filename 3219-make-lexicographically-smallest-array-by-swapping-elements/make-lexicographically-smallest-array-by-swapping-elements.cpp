class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n=nums.size();
        vector<int>temp(nums.begin(),nums.end());
        sort(temp.begin(),temp.end());

        int idx=0;
        unordered_map<int,queue<int>>mp;
        mp[idx].push(temp[0]);
        for(int i=1;i<n;i++){
            if(temp[i]-temp[i-1]<=limit){
                mp[idx].push(temp[i]);
            }else{
                idx++;
                mp[idx].push(temp[i]);
            }
        }
        unordered_map<int,queue<int>>temp_mp(mp.begin(),mp.end());
        unordered_map<int,int>check;
        for(auto x:temp_mp){
            while(!x.second.empty()){
                check[x.second.front()]=x.first;
                x.second.pop();
            }
        }
        for(int i=0;i<n;i++){
            int find_set=check[nums[i]];
            nums[i]=mp[find_set].front();
            mp[find_set].pop();
        }
        return nums;
    }
};