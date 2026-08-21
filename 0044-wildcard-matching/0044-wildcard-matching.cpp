class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        // dp[i][j] = does s[0..i-1] match p[0..j-1]
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        
        dp[0][0] = true;  // empty matches empty
        
        // initialize dp for empty s with pattern having '*'
        for (int j = 1; j <= m; ++j) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 1];
            }
        }
        
        // fill dp for all substrings
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (p[j - 1] == '*') {
                    // '*' can match empty sequence (dp[i][j-1])
                    // or match one more char from s (dp[i-1][j])
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                } else if (p[j - 1] == '?' || s[i - 1] == p[j - 1]) {
                    // match single char or '?'
                    dp[i][j] = dp[i - 1][j - 1];
                }
            }
        }
        
        return dp[n][m];
    }
};
