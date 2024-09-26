class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        
        // Start from the last digit and move towards the front
        for (int i = n - 1; i >= 0; --i) {
            // Increment the current digit
            if (digits[i] < 9) {
                digits[i]++;
                return digits; // No carry needed, return the result
            }
            // If the digit was 9, set it to 0 and continue the carry
            digits[i] = 0;
        }
        
        // If we exit the loop, it means we need to add a new most significant digit
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
