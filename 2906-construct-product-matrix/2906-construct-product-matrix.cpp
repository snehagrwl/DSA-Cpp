class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int MOD = 12345;
        
        // Initialize the result matrix with 1s
        vector<vector<int>> p(n, vector<int>(m, 1));
        
        // Forward pass: calculate prefix products
        long long prefix = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                p[i][j] = prefix;
                // Update prefix for the next element
                prefix = (prefix * grid[i][j]) % MOD;
            }
        }
        
        // Backward pass: calculate suffix products and multiply with prefix
        long long suffix = 1;
        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                p[i][j] = (p[i][j] * suffix) % MOD;
                // Update suffix for the previous element
                suffix = (suffix * grid[i][j]) % MOD;
            }
        }
        
        return p;
    }
};