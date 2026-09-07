class Solution {
public:
    int distinctSubseqII(string s) {
        // Array to store counts of subsequences ending with each character
        vector<long long> end(26, 0); 
        long long mod = 1e9 + 7;
        long long total = 0; // Total distinct subsequences found so far
        
        for (char c : s) {
            int idx = c - 'a';
            long long old_end = end[idx]; // Store the previous count for this character
            
            // The new count of subsequences ending in 'c'
            end[idx] = (total + 1) % mod;
            
            // Update the total, being careful with modulo arithmetic for negative numbers
            total = (total + end[idx] - old_end + mod) % mod;
        }
        
        return total;
    }
};