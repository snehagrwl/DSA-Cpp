class Solution {
public:
    int maximum(vector<int>& nums){
         int maxi=INT_MIN;
            for(int i=0;i<nums.size();i++){
                maxi=max(maxi,nums[i]);
            }
            return maxi;
    }
    int largestInteger(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> freq;
            for(int num:nums){
                freq[num]++;
            }
        if(k==nums.size()){
            return maximum(nums);
        }
        if(k==1){
            int ans=-1;
            for(auto& [val,count]:freq){
                if(count==1) ans=max(ans,val);
            }
            return ans;
        }
        int ans = -1;
        if (freq[nums[0]] == 1) {
            ans = max(ans, nums[0]);
        }
        if (freq[nums[n - 1]] == 1) {
            ans = max(ans, nums[n - 1]);
        }

        return ans;

    }
};