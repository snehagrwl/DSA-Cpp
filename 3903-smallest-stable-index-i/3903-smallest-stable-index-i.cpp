class Solution {
public:
    int maxi(vector<int>& nums,int i){
        int curr_max=nums[0];
        for(int j=1;j<=i;j++){
            if(nums[j]>curr_max) curr_max=nums[j];
        }
        return curr_max;
    }
    int mini(vector<int>& nums,int i){
        int curr_mini=nums[i];
        for(int j=i;j<nums.size();j++){
            if(nums[j]<curr_mini) curr_mini=nums[j];
        }
        return curr_mini;
    }
    int firstStableIndex(vector<int>& nums, int k) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            int maximum=maxi(nums,i);
            int minimum=mini(nums,i);
            if(maximum-minimum<=k) ans.push_back(i);
        }
        if(ans.size()==0) return -1;
        return mini(ans,0);
    }
};