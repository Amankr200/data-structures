class Solution {
public:
   void setZeroes(vector<vector<int>>& matrix) {
    int n = matrix.size();    // Number of rows
    int m = matrix[0].size(); // Number of columns

    // Step 1: Check if the first row and first column need to be zeroed
    bool firstRowZero = false;
    bool firstColZero = false;

    // Check if the first row contains any zero
    for (int j = 0; j < m; j++) {
        if (matrix[0][j] == 0) {
            firstRowZero = true;
            break;
        }
    }

    // Check if the first column contains any zero
    for (int i = 0; i < n; i++) {
        if (matrix[i][0] == 0) {
            firstColZero = true;
            break;
        }
    }

    // Step 2: Use the first row and first column to mark zeros
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (matrix[i][j] == 0) {
                // Mark the corresponding cell in the first row and first column
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    // Step 3: Zero out cells based on marks in the first row and first column
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }

    // Step 4: Zero out the first row if needed
    if (firstRowZero) {
        for (int j = 0; j < m; j++) {
            matrix[0][j] = 0;
        }
    }

    // Step 5: Zero out the first column if needed
    if (firstColZero) {
        for (int i = 0; i < n; i++) {
            matrix[i][0] = 0;
        }
    }
}
};
