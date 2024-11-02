class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        int maxLength = 0;
        int lastInvalid = -1; // Last index of invalid parentheses

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(i); // Push the index of '('
            } else {
                if (!st.empty()) {
                    st.pop(); // Found a matching '('
                    if (st.empty()) {
                        // All opened are matched
                        maxLength = max(maxLength, i - lastInvalid);
                    } else {
                        // There are still some unmatched '('
                        maxLength = max(maxLength, i - st.top());
                    }
                } else {
                    // No matching '(', mark this as last invalid
                    lastInvalid = i;
                }
            }
        }

        return maxLength;
    }
};
