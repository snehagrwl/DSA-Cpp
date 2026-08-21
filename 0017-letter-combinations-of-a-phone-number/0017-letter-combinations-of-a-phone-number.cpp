
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        // If input is empty, just return empty vector
        if (digits.empty()) return {};

        // Map digits to letters - phone keypad mapping
        vector<string> mapping = {
            "",     // 0 (no letters)
            "",     // 1 (no letters)
            "abc",  // 2
            "def",  // 3
            "ghi",  // 4
            "jkl",  // 5
            "mno",  // 6
            "pqrs", // 7
            "tuv",  // 8
            "wxyz"  // 9
        };

        vector<string> result;
        string current;
        backtrack(digits, 0, mapping, current, result);
        return result;
    }

private:
    void backtrack(const string& digits, int index, const vector<string>& mapping, string& current, vector<string>& result) {
        // Base case: if index reached end of digits, push current combination
        if (index == digits.size()) {
            result.push_back(current);
            return;
        }

        // Get letters for current digit
        int digit = digits[index] - '0';
        string letters = mapping[digit];

        // For each letter, add to current and recurse for next digit
        for (char letter : letters) {
            current.push_back(letter);               // Choose letter
            backtrack(digits, index + 1, mapping, current, result); // Explore
            current.pop_back();                      // Backtrack
        }
    }
};
