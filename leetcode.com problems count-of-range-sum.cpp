#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<long long> prefixSums(n + 1, 0);

        // Step 1: Calculate the prefix sums
        for (int i = 0; i < n; ++i) {
            prefixSums[i + 1] = prefixSums[i] + nums[i];
        }

        // Step 2: Use merge sort to count the range sums
        return countMergeSort(prefixSums, 0, n + 1, lower, upper);
    }

private:
    int countMergeSort(vector<long long>& prefixSums, int start, int end, int lower, int upper) {
        if (end - start <= 1) {
            return 0; // Base case, no subarrays to count
        }
        
        int mid = (start + end) / 2;
        int count = 0;

        // Recursively count in both halves
        count += countMergeSort(prefixSums, start, mid, lower, upper);
        count += countMergeSort(prefixSums, mid, end, lower, upper);

        // Step 3: Count valid ranges during the merge step
        int j = mid, k = mid;
        for (int i = start; i < mid; ++i) {
            while (j < end && prefixSums[j] - prefixSums[i] < lower) {
                ++j; // Move j to find the first prefix sum >= lower
            }
            while (k < end && prefixSums[k] - prefixSums[i] <= upper) {
                ++k; // Move k to find the last prefix sum <= upper
            }
            count += k - j; // The number of valid subarrays for prefixSums[i]
        }

        // Step 4: Merge the two halves while keeping the array sorted
        vector<long long> merged;
        int left = start, right = mid;
        while (left < mid && right < end) {
            if (prefixSums[left] <= prefixSums[right]) {
                merged.push_back(prefixSums[left++]);
            } else {
                merged.push_back(prefixSums[right++]);
            }
        }
        while (left < mid) merged.push_back(prefixSums[left++]);
        while (right < end) merged.push_back(prefixSums[right++]);

        // Copy merged array back into prefixSums
        for (int i = 0; i < merged.size(); ++i) {
            prefixSums[start + i] = merged[i];
        }

        return count;
    }
};
