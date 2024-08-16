class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> results;
        vector<int> current;
        vector<bool> used(nums.size(), false);
        
        // Sort the numbers to handle duplicates easily
        sort(nums.begin(), nums.end());
        
        // Start backtracking
        backtrack(nums, current, used, results);
        return results;
    }
    
    void backtrack(vector<int>& nums, vector<int>& current, vector<bool>& used, vector<vector<int>>& results) {
        // If the current permutation is of the same size as nums, add it to results
        if (current.size() == nums.size()) {
            results.push_back(current);
            return;
        }
        
        for (int i = 0; i < nums.size(); ++i) {
            // Skip the number if it is already used or if it is a duplicate (to avoid duplicate permutations)
            if (used[i] || (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])) {
                continue;
            }
            
            // Choose the number
            used[i] = true;
            current.push_back(nums[i]);
            
            // Explore further
            backtrack(nums, current, used, results);
            
            // Backtrack
            used[i] = false;
            current.pop_back();
        }
    }
};
