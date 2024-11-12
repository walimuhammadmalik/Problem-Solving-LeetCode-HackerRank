class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        int totalNumbers = 1 << n; // There are 2^n numbers in the sequence
        
        for (int i = 0; i < totalNumbers; i++) {
            result.push_back(i ^ (i >> 1)); // Apply the formula to generate Gray code
        }
        
        return result;
    }
};
