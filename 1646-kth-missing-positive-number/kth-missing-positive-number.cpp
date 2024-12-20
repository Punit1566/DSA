class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        int lo=0,hi=n-1;
        int mid;
        while(lo<=hi){
            mid=lo+(hi-lo)/2;
            int total_miss=arr[mid]-mid-1;//index starts from 0;
            if(total_miss<k){
                lo=mid+1;
            }else{
                hi=mid-1;
            }
        }
        return k-(-hi-1);
        
    }
};