class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        // int lo=0,hi=n-1;
        // while(lo<=hi){
        //     int mid=lo+(hi-lo)/2;
        //     if(nums[mid])
        // }
        for(int i=0;i<n;i++){
            if(arr[i]<=k)k++;
            else{
                return k;
            }
        }
        // return n+k;
        return k;
    }
};