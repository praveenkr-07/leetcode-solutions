class Solution {
    vector<vector<int>> dp;
    int helper(int idx1 , int idx2 , string text1, string text2  ){
        if(idx1 == 0 || idx2 == 0) return 0;
        if(dp[idx1][idx2] != -1) return dp[idx1][idx2];
        else if (text1[idx1-1]==text2[idx2-1]) return dp[idx1][idx2] =  1 + helper(idx1-1,idx2-1,text1,text2);
        else return dp[idx1][idx2] = max(helper(idx1-1,idx2,text1,text2) , helper(idx1,idx2-1,text1,text2));
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int idx1 = text1.length(); int idx2 = text2.length(); 
        // dp.clear();
        // dp.resize(idx1+1 , vector<int>(idx2+1,-1));
        // return  helper(idx1,idx2,text1,text2);
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
};