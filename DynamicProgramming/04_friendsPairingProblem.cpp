//https://www.geeksforgeeks.org/problems/friends-pairing-problem5425/1
class Solution {
    vector<int> dp;
    int helper(int n){
        if(n==1 || n==2) return n;
        if(dp[n]!=-1) return dp[n];
        return dp[n] = helper(n-1) + (n-1)*helper(n-2);
    }
  public:
    int countFriendsPairings(int n) {
        dp.clear();
        dp.resize(20, -1);
        return helper(n);
    }
};
