class Solution {
public:
    double myPow(double x, int n) {
        if(n==0)return 1;
        bool neg=(n<0);
        long long N=abs((long long)n);
        double ans=1;
        if(N%2==1){
            ans=x;N--;
        }
        while(N>1){
            if(N%2==1){
                ans*=x;
                N--;
            }
            x=x*x;
            N/=2;
        }
        if(x!=ans)
            ans=(double)x*ans;
        if(neg){
            return (double)(1/ans);
        }
        return ans;
    }
};