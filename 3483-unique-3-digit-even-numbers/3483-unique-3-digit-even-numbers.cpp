class Solution {
public:
    int totalNumbers(vector<int>& digits) {
       vector<int> digit_count(10, 0);
        for (int digit : digits) {
            digit_count[digit]++;
        }
        
        int ans = 0; // Initialize a counter for the answer
        
        // Iterate over all possible 3-digit even numbers
        for (int num = 100; num < 1000; num += 2) {
            std::vector<int> curr_count(10, 0);
            int temp = num;
            
            // Extract digits and count their frequencies for the current number
            while (temp > 0) {
                curr_count[temp % 10]++;
                temp /= 10;
            }
            
            // Verify if the input array has enough of each required digit
            bool valid = true;
            for (int i = 0; i < 10; ++i) {
                if (curr_count[i] > digit_count[i]) {
                    valid = false;
                    break;
                }
            }
            
            // If we have enough digits, increment our answer count
            if (valid) {
                ans++;
            }
        }
        
        return ans;
    }
};