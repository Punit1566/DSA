class Solution {
public:
    int minBitFlips(int start, int goal) {
        int cnt=0;
        int i=0;
        while(i<32){
            int a=(1&(start>>i));
            int b=(1&(goal>>i));
            if(a!=b){
                cnt++;
            }
            i++;
        }
        return cnt;
    }
};