class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        // Create a frequency array for characters in magazine
        vector<int> freq(26, 0);
        
        // Count the frequency of each character in magazine
        for (char c : magazine) {
            freq[c - 'a']++;
        }
        
        // Check if ransomNote can be constructed from magazine
        for (char c : ransomNote) {
            if (freq[c - 'a'] == 0) {
                return false;  // If a character is missing or exhausted, return false
            }
            freq[c - 'a']--;  // Use the character
        }
        
        return true;  // If all characters in ransomNote are accounted for, return true
    }
};
