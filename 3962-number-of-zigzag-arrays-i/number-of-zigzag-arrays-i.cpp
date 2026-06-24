class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        long long MOD = 1e9 + 7;
        int m = r - l + 1;

        // Base cases
        if (m <= 0 || n <= 0) return 0;
        if (n == 1) return m % MOD;

        
        std::vector<long long> dp_down(m, 1);
        std::vector<long long> dp_up(m, 1);

        for (int i = 2; i <= n; ++i) {
            std::vector<long long> next_down(m, 0);
            std::vector<long long> next_up(m, 0);

            
            long long current_pref_sum = 0;
            for (int j = 0; j < m; ++j) {
                next_up[j] = current_pref_sum;
                current_pref_sum = (current_pref_sum + dp_down[j]) % MOD;
            }

            
            long long current_suff_sum = 0;
            for (int j = m - 1; j >= 0; --j) {
                next_down[j] = current_suff_sum;
                current_suff_sum = (current_suff_sum + dp_up[j]) % MOD;
            }

            dp_down = std::move(next_down);
            dp_up = std::move(next_up);
        }

        
        long long total_count = 0;
        for (int j = 0; j < m; ++j) {
            total_count = (total_count + dp_down[j] + dp_up[j]) % MOD;
        }

        return total_count;
    }
};