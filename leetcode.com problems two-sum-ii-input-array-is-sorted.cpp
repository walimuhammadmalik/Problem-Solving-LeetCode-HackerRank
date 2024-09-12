class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;  // Start pointer
        int right = numbers.size() - 1;  // End pointer

        // Continue until the two pointers meet
        while (left < right) {
            int sum = numbers[left] + numbers[right];  // Calculate the sum of the two numbers

            if (sum == target) {
                // Return the 1-based indices
                return {left + 1, right + 1};
            } else if (sum < target) {
                // If the sum is less than the target, move the left pointer to the right
                left++;
            } else {
                // If the sum is greater than the target, move the right pointer to the left
                right--;
            }
        }

        // If no solution is found, return an empty vector (shouldn't happen as per problem constraints)
        return {};
    }
};
