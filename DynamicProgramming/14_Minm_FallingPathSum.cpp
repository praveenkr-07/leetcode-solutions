// Brute Force
class Solution {
    int helper(int i , int j , vector<vector<int>>& matrix ){
        
        if(j<0 || j >= matrix[0].size()) return INT_MAX;
        if(i==matrix.size()-1) return matrix[i][j];

        int down = helper(i+1,j,matrix);
        if(down != INT_MAX) down += matrix[i][j];

        int diagLeft = helper(i+1,j-1,matrix);
        if(diagLeft != INT_MAX) diagLeft += matrix[i][j];

        int diagRight = helper(i+1,j+1,matrix);
        if(diagRight != INT_MAX) diagRight += matrix[i][j];

        return min(down,min(diagLeft,diagRight));
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix[0].size();
        int i = 0;
        int ans = INT_MAX;
        for(int j = 0 ;j< matrix[0].size();j++){
            ans = min(ans, helper(i,j,matrix));
        }
        return ans;
    }
};

// Memoization
class Solution {
    vector<vector<int>> dp; 
    int helper(int i , int j , vector<vector<int>>& matrix ){

        if(j<0 || j >= matrix[0].size()) return INT_MAX;
        if(i==matrix.size()-1) return matrix[i][j];
        if(dp[i][j] != 1e9) return dp[i][j];
        int down = helper(i+1,j,matrix);
        if(down != INT_MAX) down += matrix[i][j];

        int diagLeft = helper(i+1,j-1,matrix);
        if(diagLeft != INT_MAX) diagLeft += matrix[i][j];

        int diagRight = helper(i+1,j+1,matrix);
        if(diagRight != INT_MAX) diagRight += matrix[i][j];

        return dp[i][j] = min(down,min(diagLeft,diagRight));
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        dp.assign(100,vector<int>(100,1e9));
        int n = matrix[0].size();
        int i = 0;
        int ans = INT_MAX;
        for(int j = 0 ;j< n;j++){
            ans = min(ans, helper(i,j,matrix));
        }
        return ans;
    }
};


// Tabulation
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int dp[n][n];
        for(int i = 0;i<n;i++){
            dp[n-1][i] = matrix[n-1][i];
        }
        for(int i = n-2 ;i>= 0 ;i--){
            for(int j=n-1;j>=0;j--){
                int down = matrix[i][j] + dp[i+1][j];

                int diagLeft = matrix[i][j];  
                if(j==0) diagLeft = INT_MAX;
                else diagLeft += dp[i+1][j-1];

                int diagRight = matrix[i][j]; 
                if(j==n-1) diagRight = INT_MAX;
                else diagRight += dp[i+1][j+1];

                dp[i][j] = min(down,min(diagLeft,diagRight));
            }
        }
        int ans = INT_MAX;
        for(int k = 0;k<n;k++){
            ans = min(ans, dp[0][k]);
        }
        return ans;
    }
};


