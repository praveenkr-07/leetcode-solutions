class Solution {
  public:
    int longCommSubstr(string& s1, string& s2) {
        int idx1 = s1.size();
        int idx2 = s2.size();
        vector<vector<int>> dp;
        dp.clear();
        dp.resize(idx1+1 , vector<int>(idx2+1,0));
        
        for(int i1 = 0 ; i1< idx1 ; i1++) dp[i1][0] = 0 ; // BASE CASE 
        for(int i2 = 0 ; i2< idx2 ; i2++) dp[0][i2] = 0 ;// BASE CASE 
        
        int ans = -1e7;
        for(int i1 = 1; i1 <= idx1 ; i1++){
            for(int i2 = 1 ; i2 <= idx2 ; i2++){
                if(s1[i1-1]==s2[i2-1] ) {
                    dp[i1][i2] = 1+dp[i1-1][i2-1];
                    int len = dp[i1][i2];
                    ans = max(len ,ans);
                }
                else dp[i1][i2] = 0;
            }
        }
        return (ans == -1e7) ? 0 : ans;
    }
};