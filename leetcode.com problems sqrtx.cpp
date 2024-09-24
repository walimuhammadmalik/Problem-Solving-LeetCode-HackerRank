class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) return x; // Handle the cases for 0 and 1

        int left = 2, right = x / 2, mid;
        while (left <= right) {
            mid = left + (right - left) / 2; // Prevent potential overflow
            long long square = static_cast<long long>(mid) * mid; // Use long long to prevent overflow

            if (square == x) {
                return mid; // Exact square root
            } else if (square < x) {
                left = mid + 1; // Move to the right half
            } else {
                right = mid - 1; // Move to the left half
            }
        }
        return right; // The floor of the square root
    }
};
