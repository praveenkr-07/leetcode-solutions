class Solution {
    int longestCommonSubsequence(string text1, string text2) {
        int idx1 = text1.length(); int idx2 = text2.length(); 
        vector<vector<int>> dp;
        dp.clear();
        dp.resize(idx1+1 , vector<int>(idx2+1,0));
        for(int i1 = 0 ; i1< idx1 ; i1++) dp[i1][0] = 0 ;
        for(int i2 = 0 ; i2< idx2 ; i2++) dp[0][i2] = 0 ;
        for(int i1 = 1; i1 <= idx1 ; i1++){
            for(int i2 = 1 ; i2 <= idx2 ; i2++){
                if(text1[i1-1]==text2[i2-1]) dp[i1][i2] = 1+dp[i1-1][i2-1];
                else dp[i1][i2] = max(dp[i1-1][i2] , dp[i1][i2-1]);
            }
        }
        return dp[idx1][idx2];
        }
public:
    int longestPalindromeSubseq(string s) {
        string s1 = s;
        reverse(s1.begin(), s1.end());
        return longestCommonSubsequence(s,s1);
        
    }
};