class Solution {
    vector<vector<int>> dp;
    int helper(int idx , int amount , vector<int> & coins){
        if(idx==0){
            if(amount % coins[0] == 0) return amount/coins[0];
            return 1e9;
        }
        if(dp[idx][amount]!=-1) return dp[idx][amount];
        int notTake = 0 + helper(idx-1,amount , coins);
        int take = 1e9;
        if(amount>=coins[idx]) take = 1 + helper(idx,amount-coins[idx],coins);
        return dp[idx][amount] = min(take,notTake); 

    }
public:
    int coinChange(vector<int>& coins, int amount) {
        dp.clear();
        dp.assign(coins.size(),vector<int>(amount+1,-1));
        int ans =  helper(coins.size()-1,amount , coins);

        if(ans>=1e9) return -1;
        return ans;
    }
};

// tabulation
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp;
        dp.clear();
        dp.assign(coins.size(),vector<int>(amount+1,1e9));
        // int ans =  helper(coins.size()-1,amount , coins);
        for(int target = 0 ; target<= amount ; target++){
            if(target % coins[0] == 0)  dp[0][target] = target / coins[0];
        }

        for(int idx = 1 ;idx<coins.size();idx++){
            for(int target = 0 ; target <= amount ; target++){
                int notTake = 0 + dp[idx-1][target];
                int take = 1e9;
                if(target>=coins[idx]) take = 1 + dp[idx][target-coins[idx]];
                dp[idx][target] = min(take,notTake);
            }
        }
        return (dp[coins.size()-1][amount] >= 1e9) ? -1 : dp[coins.size()-1][amount] ;
    }


};