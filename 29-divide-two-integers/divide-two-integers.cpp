class Solution {
public:
    int divide(int dividend, int divisor) {
        int sign=1;
        if(dividend>=0&&divisor<0)sign=0;
        if(dividend<=0&&divisor>0)sign=0;
        long dividend1=abs((long)dividend);
        long divisor1=abs((long)divisor);
        long ans=0;
        while(dividend1>=divisor1){
            int cnt=0;
            while(dividend1>(divisor1<<(cnt+1))){
                cnt++;
            }
            ans+=(1<<cnt);
            dividend1-=(divisor1<<(cnt));
        }
        if(sign){
            if(ans>=INT_MAX)return INT_MAX;
            else return ans;
        }
        if(ans<=INT_MIN)return INT_MIN;
        return -ans;
    }
};