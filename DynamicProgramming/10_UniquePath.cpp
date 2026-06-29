class Solution {
    vector<vector<int>> dp;
    int helper(int er , int ec){
        dp[1][1] = 1;
        for (int i = 1; i <= er; i++) {
            for (int j = 1; j <= ec; j++) {

                if (i == 1 && j == 1) continue;

                int rightways = 0;
                if(j-1>=1) rightways = dp[i][j-1];
                else rightways = 0;

                 int downways = 0;
                if(i-1>=1) downways = dp[i-1][j];
                else downways = 0;

                dp[i][j] = rightways + downways;
            }
        }
        return dp[er][ec];
    }
public:
    int uniquePaths(int er , int ec) {
        dp.clear();
        dp.assign(er + 1, vector<int>(ec + 1, 0));
        return helper(er,ec);
    }
};