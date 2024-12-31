class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorval=0;
        for(auto x:nums)xorval^=x;
        int right_set;
        if(xorval!=INT_MIN)
            right_set=((xorval)&(xorval-1))^xorval;
        else
            right_set=1<<31;
        int b1=0,b2=0;
        for(auto x:nums){
            if(x&right_set){
                b1^=x;
            }else{
                b2^=x;
            }
        }
        return {b1,b2};
    }
};