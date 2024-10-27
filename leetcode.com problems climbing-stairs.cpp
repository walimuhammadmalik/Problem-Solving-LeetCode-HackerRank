class Solution {
public:
    int climbStairs(int n) {
        if (n <= 1) return 1; // Base case: 1 way to climb 0 or 1 step

        int first = 1; // ways to climb 0 steps
        int second = 1; // ways to climb 1 step
        int current;

        for (int i = 2; i <= n; ++i) {
            current = first + second; // Total ways to climb to the current step
            first = second; // Move to the next step
            second = current; // Update second to current
        }

        return second; // The number of ways to climb n steps
    }
};
