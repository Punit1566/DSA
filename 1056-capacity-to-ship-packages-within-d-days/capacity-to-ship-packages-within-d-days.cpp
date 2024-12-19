class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int lo=*max_element(weights.begin(),weights.end());
        int hi=accumulate(weights.begin(),weights.end(),0);
        int ans=INT_MAX;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            int cnt=0;
            int sum=0;
            for(int i=0;i<n;i++){
                sum+=weights[i];
                if(sum>mid){
                    sum=weights[i];
                    cnt++;
                }else if(sum==mid){
                    sum=0;
                    cnt++;
                }
            }
            if(sum<=mid&&sum>0)cnt++;
            else if(sum>mid)cnt+=2;
            cout<<"lo:"<<lo<<" hi:"<<hi<<endl;
            cout<<"cnt:"<<cnt<<endl;
            if(cnt<=days){
                hi=mid-1;
                ans=min(mid,ans);
            }else{
                lo=mid+1;
            }

        }
        return ans;

    }
};