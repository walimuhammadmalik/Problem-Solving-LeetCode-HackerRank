class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) {
            return false; // Strings of different lengths cannot be isomorphic
        }
        
        unordered_map<char, char> map_s_to_t;
        unordered_map<char, char> map_t_to_s;
        
        for (int i = 0; i < s.length(); ++i) {
            char s_char = s[i];
            char t_char = t[i];
            
            // Check the mapping from s to t
            if (map_s_to_t.count(s_char)) {
                if (map_s_to_t[s_char] != t_char) {
                    return false; // Inconsistent mapping
                }
            } else {
                map_s_to_t[s_char] = t_char;
            }
            
            // Check the mapping from t to s
            if (map_t_to_s.count(t_char)) {
                if (map_t_to_s[t_char] != s_char) {
                    return false; // Inconsistent mapping
                }
            } else {
                map_t_to_s[t_char] = s_char;
            }
        }
        
        return true;
    }
};
