class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        vector<int> bitCount(31, 0);
        
        // Step 1: Count frequencies of each bit position
        for (int num : nums) {
            for (int i = 0; i <= 30; i++) {
                if ((num >> i) & 1) {
                    bitCount[i]++;
                }
            }
        }
        
        // Step 2: Build the top k numbers greedily
        vector<long long> topK(k, 0);
        for (int i = 30; i >= 0; i--) {
            int count = bitCount[i];
            for (int j = 0; j < k && count > 0; j++) {
                topK[j] |= (1LL << i);
                count--;
            }
        }
        
        // Step 3: Calculate sum of squares modulo 10^9 + 7
        long long totalSum = 0;
        long long MOD = 1e9 + 7;
        for (long long num : topK) {
            totalSum = (totalSum + (num * num) % MOD) % MOD;
        }
        
        return totalSum;
    }
};