class Solution {
    int modulo = 1e9 + 7;
    int dp[201][201][201];
    int helper(int idx , int gcdSubSeq1 , int gcdSubSeq2 , vector<int>& nums  ){
        if(idx == nums.size() ){
            if( (gcdSubSeq1 != 0 && gcdSubSeq2 != 0) && (gcdSubSeq1 == gcdSubSeq2 ))  return 1;
            return 0;
        }
        if(dp[idx][gcdSubSeq1][gcdSubSeq2] != -1 ) return dp[idx][gcdSubSeq1][gcdSubSeq2];
        int notTake = helper(idx+1,gcdSubSeq1,gcdSubSeq2,nums);
        int takeInSubSeq1 = helper(idx+1 , __gcd(gcdSubSeq1,nums[idx]) , gcdSubSeq2,nums);
        int takeInSubSeq2 = helper(idx+1 ,  gcdSubSeq1 , __gcd(gcdSubSeq2,nums[idx]),nums);
        return dp[idx][gcdSubSeq1][gcdSubSeq2] = (0LL + notTake + takeInSubSeq1  + takeInSubSeq2) % modulo;
    }
public:
    int subsequencePairCount(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return helper(0,0,0,nums);
    }
};