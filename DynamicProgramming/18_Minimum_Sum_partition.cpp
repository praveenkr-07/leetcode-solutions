class Solution {
        vector<bool> subsetSumEqualsK(vector<int>& nums,int k){
        int n = nums.size();
        vector<vector<bool>> dp;
        dp.assign(n,vector<bool>(k+1,0));
        for(int i = 0;i<n ;i++) dp[i][0] = true;
        if(nums[0] <= k) dp[0][nums[0]] = true;

        for(int i = 1 ; i<n ;i++){
            for(int target = 1 ; target <= k ; target++ ){
                bool notTake = dp[i-1][target];
                bool take = false;
                if(target >= nums[i]) take = dp[i-1][target - nums[i]];
                dp[i][target] = notTake || take;
            }
        }
        return dp[n-1];
    }
  public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        for(int i = 0 ; i<n ; i++){
            totalSum += nums[i] ;
        }
        vector<bool> dp = subsetSumEqualsK(nums,totalSum);
        
        int minDiff = 1e9;
        
        for(int i = 0; i <= totalSum/2 ; i++){
            if(dp[i] == true){
                int sum1 = i;
                int sum2 = totalSum - i; 
                minDiff = min(minDiff , abs(sum1-sum2));
            }
        }
        return minDiff;
    }
};