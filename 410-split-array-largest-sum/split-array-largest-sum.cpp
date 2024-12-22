class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        int lo=*max_element(nums.begin(),nums.end());
        int hi=accumulate(nums.begin(),nums.end(),0);
        int ans=INT_MAX;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            int cnt=0;
            int temp=0;
            for(int i=0;i<n;i++){
                if(temp+nums[i]<=mid){
                    temp+=nums[i];
                }else{
                    temp=nums[i];
                    cnt++;
                }
            }
            if(temp>0)cnt++;

            if(cnt>k){
                lo=mid+1;
            }else{
                hi=mid-1;
                ans=min(ans,mid);
            }

        }
        return ans;
    }
};