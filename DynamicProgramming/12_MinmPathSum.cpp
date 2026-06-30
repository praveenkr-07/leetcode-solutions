// Brute Force
class Solution {
    vector<vector<int>> dp;
    int helper(int i , int j , vector<vector<int>>& grid){
        if(i>= grid.size() || j>= grid[0].size()) return INT_MAX;
        if(i== grid.size() -1 && j ==  grid[0].size()-1) return grid[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int MinCost = 0;
        MinCost += grid[i][j] + min(helper(i,j+1,grid) , helper(i+1,j,grid) );
        return dp[i][j] = MinCost;
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m =  grid.size();
        int n  = grid[0].size();
        dp.clear();
        dp.assign(m,vector<int>(n,-1));
        int minCost = 0;
        minCost = helper(0,0,grid);
        return minCost;
    }
};

//Top Down or Memoization
class Solution {
    vector<vector<int>> dp;
    int helper(int i , int j , vector<vector<int>>& grid){
        if(i>= grid.size() || j>= grid[0].size()) return INT_MAX;
        if(i== grid.size() -1 && j ==  grid[0].size()-1) return grid[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int MinCost = 0;
        MinCost += grid[i][j] + min(helper(i,j+1,grid) , helper(i+1,j,grid) );
        return dp[i][j] = MinCost;
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m =  grid.size();
        int n  = grid[0].size();
        dp.clear();
        dp.assign(m,vector<int>(n,-1));
        int minCost = 0;
        minCost = helper(0,0,grid);
        return minCost;
    }
};

// Tabulation
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m =  grid.size();
        int n  = grid[0].size();
        int dp[m][n];
        for(int i = 0 ;i<m ; i++){
            for(int j = 0 ;j<n ; j++){
                if(i==0 && j == 0) dp[0][0] = grid[0][0];
                else{
                    int rightCost = grid[i][j];
                    if(j>0) rightCost = grid[i][j] +  dp[i][j-1];
                    else rightCost = INT_MAX;

                    int downCost= grid[i][j];
                    if(i>0)downCost  = grid[i][j] +  dp[i-1][j];
                    else downCost = INT_MAX;

                    dp[i][j] =  min(rightCost,downCost);
                }
            }
        }
        return dp[m-1][n-1];
    }
};
