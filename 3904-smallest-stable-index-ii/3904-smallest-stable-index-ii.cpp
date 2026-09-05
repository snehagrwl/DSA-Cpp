class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        
        // Step 1: Precompute the minimums from right to left (Suffix Min)
        vector<int> suffix_min(n);
        suffix_min[n - 1] = nums[n - 1]; // Last element is its own minimum
        for (int i = n - 2; i >= 0; i--) {
            suffix_min[i] = min(nums[i], suffix_min[i + 1]);
        }
        
        // Step 2: Iterate left to right, maintaining the max on the fly
        int curr_max = nums[0];
        for (int i = 0; i < n; i++) {
            curr_max = max(curr_max, nums[i]);
            
            // Step 3: Check condition in O(1) time and return early
            if (curr_max - suffix_min[i] <= k) {
                return i; 
            }
        }
        
        return -1;
    }
};