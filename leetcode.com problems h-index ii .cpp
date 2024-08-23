class Solution {
public:
    int hIndex(vector<int>& citations) {
        // Get the number of papers
        int n = citations.size();

        // Sort the citations in non-decreasing order
        sort(citations.begin(), citations.end());

        // Traverse the sorted citations to find the H-index
        for (int i = 0; i < n; i++) {
            // If citations[i] is greater than or equal to the number of papers from i to n
            if (citations[i] >= n - i) {
                // Return the number of papers from i to n
                return n - i;
            }
        }

        // If no valid h-index is found, return 0
        return 0;
    }
};
