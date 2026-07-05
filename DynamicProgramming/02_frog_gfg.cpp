// https://www.geeksforgeeks.org/problems/geek-jump/1

// Pure Brute Forece solution
class Solution
{
    int helper(int k, vector<int> &height, int idx)
    {
        if (idx == height.size() - 1)
            return 0;

        int total_min_cost = INT_MAX;

        for (int jump = 1; jump <= k; jump++)
        {
            int next_index = jump + idx;
            if (next_index < height.size())
            {
                int jump_cost = abs(height[idx] - height[next_index]);
                int total_cost = jump_cost + helper(k, height, next_index);
                total_min_cost = min(total_min_cost, total_cost);
            }
        }
        return total_min_cost;
    }

public:
    int index = 0;
    int minCost(vector<int> &height)
    {
        return helper(2, height, 0);
    }
};

int helper2(vector<int> &height, int i, int n)
{
    // Base Case 1: Already at the destination stone
    if (i == n - 1)
        return 0;

    // Base Case 2: At the second-to-last stone (only 1-step jump possible)
    if (i == n - 2)
        return abs(height[n - 2] - height[n - 1]);

    // Choice 1: Jump 1 step forward
    int jumpOne = helper2(height, i + 1, n) + abs(height[i] - height[i + 1]);

    // Choice 2: Jump 2 steps forward
    int jumpTwo = helper2(height, i + 2, n) + abs(height[i] - height[i + 2]);

    // Return the minimum of both paths
    return min(jumpOne, jumpTwo);
}

// optimized with memoization / top down
class Solution
{
    vector<int> dp;
    int helper(int k, vector<int> &height, int idx)
    {
        if (idx == height.size() - 1)
            return 0;

        if (dp[idx] != -1)
            return dp[idx];

        int total_min_cost = INT_MAX;

        for (int jump = 1; jump <= k; jump++)
        {
            int next_index = jump + idx;
            if (next_index < height.size())
            {
                int jump_cost = abs(height[idx] - height[next_index]);
                int total_cost = jump_cost + helper(k, height, next_index);
                total_min_cost = min(total_min_cost, total_cost);
            }
        }
        return dp[idx] = total_min_cost;
    }

public:
    int index = 0;
    int minCost(vector<int> &height)
    {
        dp.resize(height.size(), -1);
        return helper(2, height, 0);
    }
};

// optimized with Tabularization / bottom Up
class Solution
{
public:
    int minCost(vector<int> &height)
    {
        int k = 2;
        int n = height.size();
        vector<int> dp;
        dp.resize(n, INT_MAX);
        dp[n - 1] = 0;
        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = 1; j <= k; j++)
            {
                if (i + j < n)
                {
                    dp[i] = min(dp[i], abs(height[i] - height[i + j]) + dp[i + j]);
                }
            }
        }
        return dp[0];
    }
};
