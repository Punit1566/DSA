class Solution {
public:
    int countPrimes(int n) {
        vector<int>Prime(n,1);
        int cnt=0;
        for(int i=2;i<n;i++){
            if(Prime[i]==1){
                cnt++;
                for(long long j=(long long)i*i;j<n;j+=i){
                    Prime[j]=0;
                }
            }
        }

        return cnt;


    }
};