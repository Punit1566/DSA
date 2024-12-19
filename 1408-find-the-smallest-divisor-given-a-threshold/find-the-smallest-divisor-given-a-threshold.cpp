class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        int lo=1;
        int hi=*max_element(nums.begin(),nums.end())+1;
        int ans=INT_MAX;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            int sum=0;
            for(int i=0;i<n;i++){
                sum+=nums[i]/mid;
                if(nums[i]%mid!=0){
                    sum+=1;
                }
            }
            if(sum>threshold){
                lo=mid+1;
            }else{
                hi=mid-1;
                ans=min(ans,mid);
            }
        }
        return ans;
        
    }
};