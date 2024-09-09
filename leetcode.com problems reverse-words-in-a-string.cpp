class Solution {
public:
    string reverseWords(string s) {
        // Step 1: Remove extra spaces (leading, trailing, and in between)
        int left = 0, right = s.size() - 1;
        
        // Remove leading spaces
        while (left <= right && s[left] == ' ') left++;
        // Remove trailing spaces
        while (right >= left && s[right] == ' ') right--;
        
        // Step 2: Reverse entire string
        reverse(s.begin() + left, s.begin() + right + 1);
        
        // Step 3: Reverse each word individually
        int wordStart = left;
        for (int i = left; i <= right; ++i) {
            if (s[i] == ' ') {
                reverse(s.begin() + wordStart, s.begin() + i);
                wordStart = i + 1; // move to the next word
            }
        }
        // Reverse the last word if the string does not end with space
        reverse(s.begin() + wordStart, s.begin() + right + 1);
        
        // Step 4: Clean up any extra spaces in between the words and return the result
        string result;
        for (int i = left; i <= right; i++) {
            if (s[i] != ' ' || (result.size() > 0 && result.back() != ' ')) {
                result.push_back(s[i]);
            }
        }
        
        return result;
    }
};
