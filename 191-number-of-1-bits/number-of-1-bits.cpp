class Solution {
public:
    int hammingWeight(int n) {
        int bit_cnt=0;
        for(int i=0;i<32;i++){
            if(n&(1<<i))bit_cnt++;
        }
        return bit_cnt;
    }
};