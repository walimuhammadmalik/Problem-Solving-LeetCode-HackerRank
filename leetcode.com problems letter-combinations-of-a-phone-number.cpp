class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        
        // Map digits to letters
        vector<string> mapping = {
            "", "", "abc", "def", "ghi", "jkl", "mno", 
            "pqrs", "tuv", "wxyz"
        };
        
        vector<string> result;
        string current;
        backtrack(result, current, digits, mapping, 0);
        return result;
    }

private:
    void backtrack(vector<string>& result, string& current, const string& digits,
                   const vector<string>& mapping, int index) {
        // If the current combination is the same length as digits, add to results
        if (index == digits.size()) {
            result.push_back(current);
            return;
        }
        
        // Get the letters corresponding to the current digit
        int digit = digits[index] - '0';
        const string& letters = mapping[digit];
        
        for (char letter : letters) {
            current.push_back(letter); // Choose a letter
            backtrack(result, current, digits, mapping, index + 1); // Recurse
            current.pop_back(); // Backtrack
        }
    }
};
