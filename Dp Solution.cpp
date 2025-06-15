class Solution {
public:
    typedef long long ll;  // Define 'll' as alias for 'long long' to prevent overflow

    int dp[101][101];  // Memoization table to store results of subproblems

    // Recursive function to compute the minimum falling path sum from cell (i, j)
    ll hlo(vector<vector<int>>& matrix, int i, int j, int m, int n) {
        // If out of matrix bounds, return a large value (invalid path)
        if (i < 0 || j < 0 || i >= m || j >= n)
            return 1e9;

        // If already computed, return the stored result
        if (dp[i][j] != -1)
            return dp[i][j];

        // If on the last row, the value at this cell is the path sum
        if (i == m - 1)
            return matrix[i][j];

        // Explore all three possible directions in the next row
        ll first = matrix[i][j] + hlo(matrix, i + 1, j + 1, m, n); // diagonally right
        ll second = matrix[i][j] + hlo(matrix, i + 1, j, m, n);     // straight down
        ll third = matrix[i][j] + hlo(matrix, i + 1, j - 1, m, n);  // diagonally left

        // Store and return the minimum of all three options
        return dp[i][j] = min({first, second, third});
    }

    // Function to initiate recursion and return overall minimum falling path sum
    int minFallingPathSum(vector<vector<int>>& matrix) {
        ll ans = INT_MAX;  // Initialize answer with a very large number
        int m = matrix.size();       // Number of rows
        int n = matrix[0].size();    // Number of columns

        // Try starting from each column in the top row
        for (int i = 0; i < n; i++) {
            memset(dp, -1, sizeof(dp));               // Reset DP table for fresh computation
            ll p = hlo(matrix, 0, i, m, n);            // Compute path sum starting from (0, i)
            ans = min(ans, p);                         // Update the global minimum
        }

        return (int)ans;  // Return the minimum path sum as an integer
    }
};
