class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        int maxlen=0;
        int left=0;
        for(int right=0;right<nums.size();++right){
            freq[nums[right]]++;
            while(freq[nums[right]]>k){
                freq[nums[left]]--;
                left++;
            }
            maxlen=max(maxlen,right-left+1);
        }
        return maxlen;
    }
};