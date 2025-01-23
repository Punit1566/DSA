class Solution {
public:
    int solve(vector<int>& nums, int k){
        if(k<0)return 0;
        int cnt=0,ans=0;
        int lo=0,hi=0,n=nums.size();
        while(hi<n){
            if(nums[hi]&1){
                cnt++;
            }
            while(lo<=hi&&cnt>k){
                if(nums[lo]&1)cnt--;
                lo++;
            }
            ans+=(hi-lo+1);
            hi++;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return solve(nums,k)-solve(nums,k-1);
    }
};