class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int count=0;
        int n=nums.size();
        for(int i=1;i<=n;i++){
            if(n%i==0){
                count=count+pow(nums[i-1],2);
            }
        }
        return count;
    }
};