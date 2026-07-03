class Solution {
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<vector<bool>> dp;
        dp.assign(arr.size(),vector<bool>(sum+1,false));
        for(int i = 0;i<n;i++){
            dp[i][0] = true;
        }
        if (arr[0] <= sum) dp[0][arr[0]] = true;
        
        for(int i = 1; i<n ;i++){
            for(int target = 1 ; target<=sum ; target++ ){
                bool notTake = dp[i-1][target];
                bool take = false;
                if(target >= arr[i] ) take = dp[i-1][target - arr[i]];
                dp[i][target] = (notTake || take);
            }
        }
        return dp[n-1][sum];
    }
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        for(int i = 0;i<n;i++) totalSum += nums[i];
        if(totalSum % 2 != 0) return false;
        return isSubsetSum(nums,totalSum/2);
    }
};