class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();               // Number of rows
        int n = matrix[0].size();            // Number of columns

        // Initialize a DP table where dp[i][j] represents the minimum path sum to reach cell (i, j)
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        int ans = INT_MAX;  // To store the final answer

        // Fill the DP table row by row (top to bottom)
        for (int j = 0; j < m; j++) {        // Row-wise traversal
            for (int i = 0; i < n; i++) {    // Column-wise traversal

                // Base case: First row is the same as the input matrix
                if (j == 0) {
                    dp[j][i] = matrix[j][i];
                }

                // Middle columns: check diagonally left, directly above, and diagonally right
                else if (i + 1 < n && i - 1 >= 0) {
                    dp[j][i] = min({
                        matrix[j][i] + dp[j - 1][i - 1],   // from top-left
                        matrix[j][i] + dp[j - 1][i],       // from top
                        matrix[j][i] + dp[j - 1][i + 1]    // from top-right
                    });
                }

                // Left edge: only top and top-right are valid
                else if (i + 1 < n) {
                    dp[j][i] = min({
                        matrix[j][i] + dp[j - 1][i],       // from top
                        matrix[j][i] + dp[j - 1][i + 1]    // from top-right
                    });
                }

                // Right edge: only top and top-left are valid
                else if (i - 1 >= 0) {
                    dp[j][i] = min({
                        matrix[j][i] + dp[j - 1][i],       // from top
                        matrix[j][i] + dp[j - 1][i - 1]    // from top-left
                    });
                }

                // If we’re at the last row, update the global minimum
                if (j == m - 1) {
                    ans = min(ans, dp[j][i]);
                }
            }
        }

        // Return the minimum falling path sum from top to bottom
        return ans;
    }
};
