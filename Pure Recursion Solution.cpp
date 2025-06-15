class Solution {
public:
    typedef long long ll;  // Define 'll' for convenience to avoid integer overflow

    // Recursive helper function to compute minimum falling path sum from cell (i, j)
    ll hlo(vector<vector<int>>& matrix, int i, int j, int m, int n) {
        // Base case: If out of matrix bounds, return a large number (invalid path)
        if (i < 0 || j < 0 || i >= m || j >= n) {
            return 1e9;
        }

        // If we're on the last row, just return the value of the current cell
        if (i == m - 1)
            return matrix[i][j];

        // Move diagonally right, straight down, or diagonally left to next row
        ll first = matrix[i][j] + hlo(matrix, i + 1, j + 1, m, n);
        ll second = matrix[i][j] + hlo(matrix, i + 1, j, m, n);
        ll third = matrix[i][j] + hlo(matrix, i + 1, j - 1, m, n);

        // Return the minimum sum path among the three choices
        return min({first, second, third});
    }

    // Main function to find the minimum falling path sum
    int minFallingPathSum(vector<vector<int>>& matrix) {
        ll ans = INT_MAX;  // Initialize answer to a very large value
        int m = matrix.size();        // Number of rows
        int n = matrix[0].size();     // Number of columns

        // Try starting from every column in the first row
        for (int i = 0; i < n; i++) {
            long long p = hlo(matrix, 0, i, m, n);  // Recursive call for each starting point
            ans = min(ans, p);  // Update global minimum
        }

        return (int)ans;  // Return the final answer as an integer
    }
};
