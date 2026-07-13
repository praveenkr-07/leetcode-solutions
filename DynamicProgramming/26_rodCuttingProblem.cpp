class Solution
{
  vector<vector<int>> dp;
  int helper(int i, int len, vector<int> &cuts)
  {
    if (i == 0)
    {
      return len * cuts[0];
    }
    if (dp[i][len] != -1)
      return dp[i][len];
    int notTake = 0 + helper(i - 1, len, cuts);
    int take = INT_MIN;
    int rodLength = i + 1;
    if (rodLength <= len)
      take = cuts[i] + helper(i, len - rodLength, cuts);
    return dp[i][len] = max(take, notTake);
  }

public:
  int cutRod(vector<int> &price)
  {
    int n = price.size();
    vector<vector<int>> dp;
    dp.clear();
    dp.resize(n, vector<int>(n + 1, -1));

    // base case
    for (int i = 0; i <= n; i++)
    {
      dp[0][i] = i * price[0];
    }

    for (int i = 1; i < n; i++)
    {
      for (int len = 0; len <= n; len++)
      {
        int notTake = 0 + dp[i - 1][len];
        int take = INT_MIN;
        int rodLength = i + 1;
        if (rodLength <= len)
          take = price[i] + dp[i][len - rodLength];
        dp[i][len] = max(take, notTake);
      }
    }

    return dp[n - 1][n];
  }
};