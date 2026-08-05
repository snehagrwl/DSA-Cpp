class Solution {
public:
void backtrack(int start, int n, int k, vector<int>& current, vector<vector<int>>& ans) {
        // Base Case: when current combination reaches size k
        if (current.size() == k) {
            ans.push_back(current);
            return;
        }

        // Try every candidate starting from `start` up to `n`
        for (int i = start; i <= n; i++) {
            // Include element
            current.push_back(i);
            
            // Recurse to next element
            backtrack(i + 1, n, k, current, ans);
            
            // Backtrack: remove last element
            current.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> current;
        backtrack(1, n, k, current, ans);
        return ans;
    }
   
};