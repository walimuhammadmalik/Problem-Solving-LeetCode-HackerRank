class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current;
        generate(n, n, current, result);
        return result;
    }

private:
    void generate(int left, int right, string& current, vector<string>& result) {
        if (left == 0 && right == 0) {
            result.push_back(current);
            return;
        }
        
        if (left > 0) {
            current.push_back('(');
            generate(left - 1, right, current, result);
            current.pop_back(); // backtrack
        }
        
        if (right > left) { // ensure we have more closing than opening
            current.push_back(')');
            generate(left, right - 1, current, result);
            current.pop_back(); // backtrack
        }
    }
};
