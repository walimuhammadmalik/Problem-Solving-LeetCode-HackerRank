class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;

        // Traverse both strings from the end
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;

            if (i >= 0) {
                sum += a[i] - '0';  // Convert char to int and add to sum
                i--;
            }

            if (j >= 0) {
                sum += b[j] - '0';  // Convert char to int and add to sum
                j--;
            }

            carry = sum / 2;  // Compute carry (either 0 or 1)
            result += (sum % 2) + '0';  // Append the result bit ('0' or '1')
        }

        reverse(result.begin(), result.end());  // The result is currently in reverse order
        return result;
    }
};
