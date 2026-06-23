class Solution {
    
    int helper(int k , vector<int>& height , int idx){
        int n = height.size();
        vector<int> dp;
        dp.resize(n , INT_MAX);
        dp[n-1]=0;
        for(int i = n-2 ; i >=0 ; i--){
            for(int j = 1 ;j<= k ; j++){
                if( i+j < n){
                    dp[i] = min(dp[i],abs(height[i]-height[i+j]) + dp[i+j]);
                }
            }
        }
        return dp[0];
    }
  public:
    int index = 0;
    int minCost(vector<int>& height) {
        return helper(2,height,0);
    }
}; 