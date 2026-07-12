class Solution {
    vector<vector<int>> dp;
    int helper(int index , int capacity ,vector<int> &val, vector<int> &wt ){
        if(index==0){
            if(capacity >= wt[index] ) return (capacity / wt[index])*val[0];
            return 0;
        }
        if(dp[index][capacity]!=-1) return dp[index][capacity];
        int notTake = helper(index-1,capacity , val , wt);
        int take = INT_MIN;
        
        if(capacity >= wt[index]) take = val[index] + helper(index , capacity - wt[index] , val , wt);
        return dp[index][capacity] = max(take , notTake);
    }
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        dp.clear();
        dp.assign(val.size(),vector<int>(capacity+1,-1));
        return helper(wt.size()-1,capacity,val , wt);
    }
};