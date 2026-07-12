class Solution {
    vector<vector<int>> dp;
    int helper(int idx , int amount, vector<int>& coins){
        if(idx==0){
            if(amount % coins[0] == 0) return 1;
            else return 0;
        }
        if(dp[idx][amount]!=-1) return dp[idx][amount];
        int notTake = helper(idx-1,amount, coins);
        int take = 0;
        if(coins[idx] <= amount) take = helper(idx, amount-coins[idx], coins);
        return dp[idx][amount] = take + notTake;
    }
public:
    int change(int amount, vector<int>& coins) {
        // dp.clear();
        // dp.assign(coins.size(),vector<int>(amount+1,-1));
        //return helper(coins.size()-1 , amount , coins);
        vector<vector<unsigned long long >> dp;
        dp.clear();
        dp.assign(coins.size(),vector <unsigned long long>(amount+1,0));
        for(int target = 0 ;target <= amount ; target++){
           if(target % coins[0] == 0)  dp[0][target] = 1;
        }
        for(int idx = 1 ;idx < coins.size();idx++){
            for(int target = 0 ; target <= amount ; target++){
                unsigned long long notTake = dp[idx-1][target];
                unsigned long long take = 0;
                if(coins[idx] <= target) take = dp[idx][target-coins[idx]];
                dp[idx][target] = take + notTake;
            }
        }
        return dp[coins.size()-1][amount];
    }
};