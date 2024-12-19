class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long n=bloomDay.size();
        if(n<(long long)m*k) return -1;
        int lo=*min_element(bloomDay.begin(),bloomDay.end());
        int hi=*max_element(bloomDay.begin(),bloomDay.end());
        int ans=INT_MAX;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            int cnt=0,nk=0;
            for(int i=0;i<n;i++){
                if(bloomDay[i]<=mid){
                    cnt++;
                }else{
                    if(cnt>=k){
                        nk+=cnt/k;
                    }
                    cnt=0;
                }
            }
            if(cnt>=k){
                nk+=cnt/k;
            }
            if(nk>=m){
                hi=mid-1;
                ans=min(ans,mid);
            }else{
                lo=mid+1;
            }
        }
        return ans;
    }
};