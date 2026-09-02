class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int sum=0;
        for(int i=0;i<nums1.size();i++){
            sum+=nums1[i];
        }
        if(sum%2==0) return true;
        else{
            int odd_element;
            int i=0;
            while(i<nums1.size()){
                if(nums1[i]%2!=0) break;
                i++;
            }
            for(int j=0;j<nums1.size();j++){
                if(nums1[j]%2!=0) continue;
                nums1[j]-=nums1[i];
            }
            return true;
        }
    }
};