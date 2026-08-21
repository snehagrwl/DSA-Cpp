class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0, maxLen = 1;
        int n = s.size();

        // Helper lambda to expand around center
        auto expand = [&](int left, int right) {
            // expand while characters are equal and within bounds
            while (left >= 0 && right < n && s[left] == s[right]) {
                left--;
                right++;
            }
            // After exiting while loop, left and right are one step beyond palindrome bounds
            int len = right - left - 1;
            if (len > maxLen) {
                maxLen = len;
                start = left + 1;
            }
        };

        for (int i = 0; i < n; i++) {
            // Odd length palindrome
            expand(i, i);
            // Even length palindrome
            expand(i, i + 1);
        }

        return s.substr(start, maxLen);
    }
};
