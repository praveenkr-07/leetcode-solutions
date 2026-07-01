// Brute Force
class Solution
{
    int helper(int i, int j1, int j2, vector<vector<int>> &grid)
    {

        if (i < 0 || j1 >= grid[0].size() || j2 >= grid[0].size())
            return -1e8;

        if (i == grid.size() - 1)
        {
            if (j1 == j2)
                return grid[i][j2];
            else
                return grid[i][j1] + grid[i][j2];
        }

        int maxmCherries = 0;
        for (int dj1 = -1; dj1 <= 1; dj1++)
        {
            for (int dj2 = -1; dj2 <= 1; dj2++)
            {
                if (j1 == j2)
                    maxmCherries = max(maxmCherries, grid[i][j1] + helper(i + 1, j1 + dj1, j2 + dj2, grid));
                else
                    maxmCherries = max(maxmCherries, grid[i][j1] + grid[i][j2] + helper(i + 1, j1 + dj1, j2 + dj2, grid));
            }
        }
        return maxmCherries;
    }

public:
    int cherryPickup(vector<vector<int>> &grid)
    {
        int i = 0;
        int j1 = 0;
        int j2 = grid[0].size() - 1;
        return helper(i, j1, j2, grid);
    }
};

// Memoization using 3D vector
class Solution
{
    vector<vector<vector<int>>> dp;
    int helper(int i, int j1, int j2, vector<vector<int>> &grid)
    {

        if (i < 0 || j1 >= grid[0].size() || j2 >= grid[0].size())
            return -1e8;

        if (i == grid.size() - 1)
        {
            if (j1 == j2)
                return grid[i][j2];
            else
                return grid[i][j1] + grid[i][j2];
        }
        if (dp[i][j1][j2] != -1)
            return dp[i][j1][j2];

        int maxmCherries = 0;
        for (int dj1 = -1; dj1 <= 1; dj1++)
        {
            for (int dj2 = -1; dj2 <= 1; dj2++)
            {
                if (j1 == j2)
                    maxmCherries = max(maxmCherries, grid[i][j1] + helper(i + 1, j1 + dj1, j2 + dj2, grid));
                else
                    maxmCherries = max(maxmCherries, grid[i][j1] + grid[i][j2] + helper(i + 1, j1 + dj1, j2 + dj2, grid));
            }
        }
        return dp[i][j1][j2] = maxmCherries;
    }

public:
    int cherryPickup(vector<vector<int>> &grid)
    {
        int r = grid.size();
        int c = grid[0].size();
        dp.assign(r, vector<vector<int>>(c, vector<int>(c, -1)));
        int i = 0;
        int j1 = 0;
        int j2 = grid[0].size() - 1;
        return helper(i, j1, j2, grid);
    }
};
