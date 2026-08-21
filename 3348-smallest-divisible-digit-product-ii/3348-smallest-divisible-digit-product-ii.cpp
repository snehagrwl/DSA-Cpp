#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string smallestNumber(string num, long long t) {
        long long temp = t;
        int req2 = 0, req3 = 0, req5 = 0, req7 = 0;
        
        while (temp % 2 == 0) { req2++; temp /= 2; }
        while (temp % 3 == 0) { req3++; temp /= 3; }
        while (temp % 5 == 0) { req5++; temp /= 5; }
        while (temp % 7 == 0) { req7++; temp /= 7; }
        
        // Impossible if t has prime factors other than 2, 3, 5, 7
        if (temp > 1) return "-1"; 

        // DP table for min digits required for 2s and 3s
        vector<vector<int>> dp(60, vector<int>(40, 1e9));
        dp[0][0] = 0;
        for (int i = 0; i < 60; ++i) {
            for (int j = 0; j < 40; ++j) {
                if (dp[i][j] == 1e9) continue;
                int ni, nj;
                ni = min(59, i + 1); dp[ni][j] = min(dp[ni][j], dp[i][j] + 1); 
                nj = min(39, j + 1); dp[i][nj] = min(dp[i][nj], dp[i][j] + 1); 
                ni = min(59, i + 2); dp[ni][j] = min(dp[ni][j], dp[i][j] + 1); 
                ni = min(59, i + 1); nj = min(39, j + 1); dp[ni][nj] = min(dp[ni][nj], dp[i][j] + 1); 
                ni = min(59, i + 3); dp[ni][j] = min(dp[ni][j], dp[i][j] + 1); 
                nj = min(39, j + 2); dp[i][nj] = min(dp[i][nj], dp[i][j] + 1); 
            }
        }

        auto get_min_len = [&](int r2, int r3, int r5, int r7) {
            r2 = max(0, r2); r3 = max(0, r3);
            r5 = max(0, r5); r7 = max(0, r7);
            return r5 + r7 + dp[r2][r3];
        };

        int n = num.length();
        
        // Precompute prefix prime factors to make the search O(n) instead of O(n^2)
        vector<int> p2(n + 1, 0), p3(n + 1, 0), p5(n + 1, 0), p7(n + 1, 0);
        int first_zero = -1;
        
        for (int i = 0; i < n; ++i) {
            p2[i+1] = p2[i]; p3[i+1] = p3[i]; p5[i+1] = p5[i]; p7[i+1] = p7[i];
            if (num[i] == '0') {
                if (first_zero == -1) first_zero = i;
            } else {
                int d = num[i] - '0';
                while (d % 2 == 0) { p2[i+1]++; d /= 2; }
                while (d % 3 == 0) { p3[i+1]++; d /= 3; }
                while (d % 5 == 0) { p5[i+1]++; d /= 5; }
                while (d % 7 == 0) { p7[i+1]++; d /= 7; }
            }
        }
        
        // 1. Check if the original string already satisfies the condition
        if (first_zero == -1 && p2[n] >= req2 && p3[n] >= req3 && p5[n] >= req5 && p7[n] >= req7) {
            return num;
        }

        // 2. Try to find a valid lexicographical string of the same length
        // We only start searching from the first '0' (if any) because any index after it includes a '0' in its prefix
        int start_i = (first_zero == -1) ? n - 1 : first_zero;
        
        for (int i = start_i; i >= 0; --i) {
            int start_digit = max(1, num[i] - '0' + 1);
            for (int d = start_digit; d <= 9; ++d) {
                int d2 = 0, d3 = 0, d5 = 0, d7 = 0, temp_d = d;
                while (temp_d % 2 == 0) { d2++; temp_d /= 2; }
                while (temp_d % 3 == 0) { d3++; temp_d /= 3; }
                while (temp_d % 5 == 0) { d5++; temp_d /= 5; }
                while (temp_d % 7 == 0) { d7++; temp_d /= 7; }

                // Use the precomputed prefix arrays directly (O(1) lookup)
                int rem2 = max(0, req2 - p2[i] - d2);
                int rem3 = max(0, req3 - p3[i] - d3);
                int rem5 = max(0, req5 - p5[i] - d5);
                int rem7 = max(0, req7 - p7[i] - d7);
                int rem_slots = n - 1 - i;
                
                if (get_min_len(rem2, rem3, rem5, rem7) <= rem_slots) {
                    string res = num.substr(0, i) + to_string(d);
                    
                    for (int k = 0; k < rem_slots; ++k) {
                        for (int next_d = 1; next_d <= 9; ++next_d) {
                            int nd2 = 0, nd3 = 0, nd5 = 0, nd7 = 0, tnd = next_d;
                            while (tnd % 2 == 0) { nd2++; tnd /= 2; }
                            while (tnd % 3 == 0) { nd3++; tnd /= 3; }
                            while (tnd % 5 == 0) { nd5++; tnd /= 5; }
                            while (tnd % 7 == 0) { nd7++; tnd /= 7; }
                            
                            int nrem2 = max(0, rem2 - nd2);
                            int nrem3 = max(0, rem3 - nd3);
                            int nrem5 = max(0, rem5 - nd5);
                            int nrem7 = max(0, rem7 - nd7);
                            
                            if (get_min_len(nrem2, nrem3, nrem5, nrem7) <= rem_slots - 1 - k) {
                                res += to_string(next_d);
                                rem2 = nrem2; rem3 = nrem3; rem5 = nrem5; rem7 = nrem7;
                                break; 
                            }
                        }
                    }
                    return res;
                }
            }
        }

        // 3. Fallback: Build the smallest valid longer string.
        int required_len = get_min_len(req2, req3, req5, req7);
        int target_len = max(n + 1, required_len);
        
        string res = "";
        int rem2 = req2, rem3 = req3, rem5 = req5, rem7 = req7;
        
        for (int k = 0; k < target_len; ++k) {
            for (int next_d = 1; next_d <= 9; ++next_d) {
                int nd2 = 0, nd3 = 0, nd5 = 0, nd7 = 0, tnd = next_d;
                while (tnd % 2 == 0) { nd2++; tnd /= 2; }
                while (tnd % 3 == 0) { nd3++; tnd /= 3; }
                while (tnd % 5 == 0) { nd5++; tnd /= 5; }
                while (tnd % 7 == 0) { nd7++; tnd /= 7; }
                
                int nrem2 = max(0, rem2 - nd2);
                int nrem3 = max(0, rem3 - nd3);
                int nrem5 = max(0, rem5 - nd5);
                int nrem7 = max(0, rem7 - nd7);
                
                if (get_min_len(nrem2, nrem3, nrem5, nrem7) <= target_len - 1 - k) {
                    res += to_string(next_d);
                    rem2 = nrem2; rem3 = nrem3; rem5 = nrem5; rem7 = nrem7;
                    break;
                }
            }
        }
        
        return res;
    }
};