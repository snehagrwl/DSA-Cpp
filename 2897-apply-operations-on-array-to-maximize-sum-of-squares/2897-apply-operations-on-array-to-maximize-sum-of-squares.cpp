class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
       int bitCount[32]={0};
       for(int num: nums){
        for(int i=0;i<=30;i++){
            if((num>>i)&1) bitCount[i]++;
        }
       }

       long long totalsum=0;
       long long mod=1e9+7;

       for(int j=0;j<k;j++){
        long long currentnum=0;
        for(int i=30;i>=0;i--){
            if(bitCount[i]>0){
                currentnum |=(1LL<<i);
                bitCount[i]--;
            }
        }
        totalsum=(totalsum+(currentnum*currentnum)%mod)%mod;
       }
       return totalsum;
    }
};