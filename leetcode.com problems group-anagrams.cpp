class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramGroups;
        
        // Loop through each string in the input list
        for (string& s : strs) {
            // Sort the string to use it as the key
            string sortedStr = s;
            sort(sortedStr.begin(), sortedStr.end());
            
            // Use the sorted string as a key in the hash map
            anagramGroups[sortedStr].push_back(s);
        }
        
        // Prepare the result by extracting all the grouped anagrams
        vector<vector<string>> result;
        for (auto& group : anagramGroups) {
            result.push_back(group.second);
        }
        
        return result;
    }
};
