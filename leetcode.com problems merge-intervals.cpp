class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> mergedIntervals;
        
        if (intervals.empty()) {
            return mergedIntervals;  // Return an empty result if no intervals
        }

        // Sort intervals based on the start time
        sort(intervals.begin(), intervals.end());

        // Start with the first interval
        vector<int> currentInterval = intervals[0];

        for (int i = 1; i < intervals.size(); i++) {
            // Check if there is an overlap between the current and next intervals
            if (currentInterval[1] >= intervals[i][0]) {
                // Merge the intervals by updating the end time
                currentInterval[1] = max(currentInterval[1], intervals[i][1]);
            } else {
                // No overlap, push the current interval to result and move to the next
                mergedIntervals.push_back(currentInterval);
                currentInterval = intervals[i];  // Move to the next interval
            }
        }

        // Add the last interval
        mergedIntervals.push_back(currentInterval);
        
        return mergedIntervals;
    }
};
