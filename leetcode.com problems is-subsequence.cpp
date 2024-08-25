class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;

        // Traverse through both strings
        while (i < s.length() && j < t.length()) {
            // If characters match, move both pointers
            if (s[i] == t[j]) {
                i++;
            }
            // Always move the pointer for t
            j++;
        }

        // If we've gone through all of s, then it's a subsequence
        return i == s.length();
    }
};
