class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        int lo=0,hi=n-1;
        int temp=k;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;

            cout<<"mid:"<<mid<<endl;
            if(arr[mid]<=k){
                k=temp+mid+1;
                lo=mid+1;
                hi=n-1;
            }else{
                hi=mid-1;
            }
        }
        return k;
        
    }
};