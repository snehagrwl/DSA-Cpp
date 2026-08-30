
static const int fast_io = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();
class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        auto minmax = std::minmax_element(nums.begin(), nums.end());
        int min_idx = minmax.first - nums.begin();
        int max_idx = minmax.second - nums.begin();

        int first=min(min_idx,max_idx);
        int second=max(min_idx,max_idx);
        int n=nums.size();
        int front_only=second+1;
        int back_only=n-first;
        int both_ends=(first+1)+(n-second);
        return min({front_only,back_only,both_ends});
        
    }
};