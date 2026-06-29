class Solution {
    vector<vector<int>> dp;
    int helper(int m , int n ,vector<vector<int>>& obstacleGrid ){
        if(m < 1 || n < 1 ) return 0;
        if(obstacleGrid[m - 1][n - 1] == 1) return 0;
        if(m==1 && n == 1) return 1;
        if(dp[m][n] != -1 ) return dp[m][n];
        int rightways = helper(m,n-1,obstacleGrid);
        int downways =  helper(m-1,n,obstacleGrid);
        return  dp[m][n] = rightways+downways;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        dp.clear();
        dp.assign(m+1,vector<int>(n+1,-1));
        return helper(m,n,obstacleGrid);
    }
};