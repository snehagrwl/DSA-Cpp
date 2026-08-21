class Solution {
public:
    string intToRoman(int num) {
        // Think aloud: each index represents a digit from 0 to 9.
        // We store the Roman representation for ones, tens, hundreds, and thousands.
        vector<string> thousands = {"", "M", "MM", "MMM"};

        vector<string> hundreds = {
            "", "C", "CC", "CCC", "CD",
            "D", "DC", "DCC", "DCCC", "CM"
        };

        vector<string> tens = {
            "", "X", "XX", "XXX", "XL",
            "L", "LX", "LXX", "LXXX", "XC"
        };

        vector<string> ones = {
            "", "I", "II", "III", "IV",
            "V", "VI", "VII", "VIII", "IX"
        };

        // Think aloud: extract each digit based on its place value
        // and directly pick its Roman representation from the table.
        string result;

        result += thousands[num / 1000];
        result += hundreds[(num % 1000) / 100];
        result += tens[(num % 100) / 10];
        result += ones[num % 10];

        return result;
    }
};
