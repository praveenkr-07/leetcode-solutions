// Brute Force -> Pure Recursion
class Solution {
    int helper(int i , int j , vector<vector<int>>& triangle ){
        if(i == triangle.size()-1) return triangle[i][j];
        int down = triangle[i][j] + helper(i+1,j,triangle);
        int diagonal = triangle[i][j] + helper(i+1,j+1,triangle);
        return min(down,diagonal);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int i = 0;
        int j = 0;
        return helper(i,j,triangle);
    }
};

// Memoization
class Solution {
    vector<vector<int>>dp;
    int helper(int i , int j , vector<vector<int>>& triangle ){
        if(i == triangle.size()-1) return triangle[i][j];
        if(dp[i][j]  != -1) return dp[i][j];
        int down = triangle[i][j] + helper(i+1,j,triangle);
        int diagonal = triangle[i][j] + helper(i+1,j+1,triangle);
        return dp[i][j] = min(down,diagonal);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        dp.clear();
        dp.assign(n,vector<int>(n,-1));
        int i = 0;
        int j = 0;
        return helper(i,j,triangle);
    }
};

// Tabulation
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int dp[n][n];
        int j = 0;
        for(int j = 0;j<n;j++) dp[n-1][j] = triangle[n-1][j];
        for(int i = n-2 ; i >= 0 ; i--){
            for(int j = i ; j >= 0 ;j--){
                int down = triangle[i][j] +  dp[i+1][j];
                int diagonal = triangle[i][j] + dp[i+1][j+1];
                dp[i][j] = min(down,diagonal);
            }
        }
        return dp[0][0];
    }
};
