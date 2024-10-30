#include <vector>

class Solution {
public:
    std::vector<int> getRow(int rowIndex) {
        std::vector<int> row(rowIndex + 1, 1); // Initialize the row with 1s

        for (int i = 1; i <= rowIndex; ++i) {
            // Update the row from the end to avoid overwriting previous values
            for (int j = i - 1; j > 0; --j) {
                row[j] = row[j] + row[j - 1];
            }
        }

        return row;
    }
};
