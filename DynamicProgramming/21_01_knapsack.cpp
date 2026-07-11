class Solution {
    vector<vector<int>> dp;
    int helper(int index , int capacity ,vector<int> &val, vector<int> &wt ){
        if(index==0){
            if(capacity >= wt[index] ) return val[index];
            return 0;
        }
        if(dp[index][capacity]!=-1) return dp[index][capacity];
        int notTake = helper(index-1,capacity , val , wt);
        int take = INT_MIN;
        
        if(capacity >= wt[index]) take = val[index]+ helper(index-1,capacity - wt[index] , val , wt);
        return dp[index][capacity] = max(take , notTake);
    }
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        dp.clear();
        dp.assign(val.size(),vector<int>(W+1,-1));
        return helper(wt.size()-1,W,val , wt);
    }
};

// tabulation
class Solution {

  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        vector<vector<int>> dp;
        dp.clear();
        dp.assign(val.size(),vector<int>(W+1,0));
        for(int i  = wt[0];i<= W ; i++) dp[0][i] = val[0]; // Base - Case 
        for(int i = 1 ; i<wt.size();i++){
            for(int capacity = 0 ; capacity<= W ; capacity++){
                int notTake = dp[i-1][capacity];
                int take = INT_MIN;
        
                if(capacity >= wt[i]) take = val[i]+dp[i-1][capacity-wt[i]];
                dp[i][capacity] = max(take,notTake);
            }
        }
       return dp[val.size()-1][W];
        
    }
};