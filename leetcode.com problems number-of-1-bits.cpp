class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;
        while (n) {
            count += n & 1; // Increment count if the last bit is 1
            n >>= 1;        // Right shift to check the next bit
        }
        return count;
    }
};
