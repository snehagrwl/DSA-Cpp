class Solution {
public:
    int romanToInt(string s) {
        // Map to store Roman numerals and their integer values
        unordered_map<char, int> romanMap = {
            {'I', 1}, {'V', 5}, {'X', 10},
            {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
        };
        
        int result = 0; // This will store the final integer value
        
        // Iterate through the string
        for (int i = 0; i < s.size(); i++) {
            // If next value exists and is greater, subtract current value
            if (i + 1 < s.size() && romanMap[s[i]] < romanMap[s[i + 1]]) {
                result -= romanMap[s[i]];
            } else {
                // Otherwise, add the current value
                result += romanMap[s[i]];
            }
        }
        
        return result;
    }
};
