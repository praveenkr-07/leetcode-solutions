class Solution
{
public:
  string shortestCommonSupersequence(string text1, string text2)
  {
    int size1 = text1.size();
    int size2 = text2.size();
    vector<vector<int>> dp;
    dp.clear();
    dp.resize(size1 + 1, vector<int>(size2 + 1, 0));
    for (int i = 0; i < size1; i++)
      dp[i][0] = 0;
    for (int i = 0; i < size2; i++)
      dp[0][i] = 0;
    for (int idx1 = 1; idx1 <= size1; idx1++)
    {
      for (int idx2 = 1; idx2 <= size2; idx2++)
      {
        if (text1[idx1 - 1] == text2[idx2 - 1])
          dp[idx1][idx2] = 1 + dp[idx1 - 1][idx2 - 1];
        else
          dp[idx1][idx2] = max(dp[idx1 - 1][idx2], dp[idx1][idx2 - 1]);
      }
    }
    string ans = "";
    int idx1 = size1;
    int idx2 = size2;
    while (idx1 >= 1 && idx2 >= 1)
    {
      if (text1[idx1 - 1] == text2[idx2 - 1])
      {
        ans += text1[idx1 - 1];
        idx1--;
        idx2--;
      }
      else if (dp[idx1 - 1][idx2] > dp[idx1][idx2 - 1])
      {
        ans += text1[idx1 - 1];
        idx1--;
      }
      else
      {
        ans += text2[idx2 - 1];
        idx2--;
      }
    }
    while (idx1 >= 1)
    {
      ans += text1[idx1 - 1];
      idx1--;
    }

    while (idx2 >= 1)
    {
      ans += text2[idx2 - 1];
      idx2--;
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};