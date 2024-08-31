class Solution {
public:
    bool wordPattern(string pattern, string s) {
        // Step 1: Split the string s into words
        vector<string> words;
        stringstream ss(s);
        string word;
        while (ss >> word) {
            words.push_back(word);
        }
        
        // Step 2: Check if the number of words matches the length of the pattern
        if (pattern.length() != words.size()) {
            return false;
        }
        
        // Step 3: Create two maps to store the mappings
        unordered_map<char, string> charToWord;
        unordered_map<string, char> wordToChar;
        
        // Step 4: Iterate over the pattern and words simultaneously
        for (int i = 0; i < pattern.length(); ++i) {
            char c = pattern[i];
            string w = words[i];
            
            // Check if the character c already has a mapping
            if (charToWord.count(c)) {
                if (charToWord[c] != w) {
                    return false; // Inconsistent mapping
                }
            } else {
                charToWord[c] = w; // Create a new mapping
            }
            
            // Check if the word w already has a mapping
            if (wordToChar.count(w)) {
                if (wordToChar[w] != c) {
                    return false; // Inconsistent mapping
                }
            } else {
                wordToChar[w] = c; // Create a new mapping
            }
        }
        
        // If we get through the loop without problems, the pattern matches
        return true;
    }
};
