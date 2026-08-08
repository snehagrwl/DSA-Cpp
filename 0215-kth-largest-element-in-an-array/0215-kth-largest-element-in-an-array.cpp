class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int target_idx=nums.size()-k;
        nth_element(nums.begin(),nums.begin()+target_idx,nums.end());
        return nums[target_idx];
    }
};