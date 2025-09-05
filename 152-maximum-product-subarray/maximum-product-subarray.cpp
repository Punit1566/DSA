class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int ans=INT_MIN;
        int prod=1;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                ans=max(ans,0);
                prod=1;
            }
            else{
                prod*=nums[i];
                ans=max(ans,prod);
            }
        }
        prod=1;
        for(int i=n-1;i>=0;i--){
            if(nums[i]==0){
                ans=max(ans,0);
                prod=1;
            }
            else{
                prod*=nums[i];
                ans=max(ans,prod);
            }
        }
        return ans;
    }
};