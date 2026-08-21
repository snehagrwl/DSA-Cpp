class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        long long low = 1, high = 1LL * coins[0] * k;
        long long ans = high;
        
        // Helper to compute greatest common divisor
        auto gcd = [](long long a, long long b) {
            while (b) {
                long long temp = b;
                b = a % b;
                a = temp;
            }
            return a;
        };

        // Helper to compute least common multiple with overflow check
        auto lcm = [&](long long a, long long b) {
            return (a / gcd(a, b)) * b;
        };

        // Binary search for the kth smallest amount
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long count = 0;
            int n = coins.size();

            // Inclusion-exclusion principle over all subsets of coins
            for (int i = 1; i < (1 << n); ++i) {
                long long current_lcm = 1;
                int set_bits = 0;
                bool overflow = false;

                for (int j = 0; j < n; ++j) {
                    if ((i >> j) & 1) {
                        set_bits++;
                        current_lcm = lcm(current_lcm, coins[j]);
                        if (current_lcm > mid) {
                            overflow = true;
                            break;
                        }
                    }
                }

                if (!overflow) {
                    if (set_bits % 2 == 1) {
                        count += mid / current_lcm;
                    } else {
                        count -= mid / current_lcm;
                    }
                }
            }

            if (count >= k) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};