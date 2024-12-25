class Solution {
public:
    int hammingWeight(int n) {
        return bitset<64>(n).count();
    }
};