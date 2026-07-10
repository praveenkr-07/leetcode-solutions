// Memoized
class Solution {
    vector<vector<int>> dp;
    int helper(vector<int>& arr, int sum , int idx){
        if(idx==0) {
            if(sum == 0 && arr[0] == sum) return 2 ;
            if(sum == 0 || arr[0]== sum) return 1;
            else return 0;
        }
    if(dp[idx][sum] != -1) return dp[idx][sum];
        int notTake = helper(arr,sum,idx-1);
        int take = 0;
        if(sum >= arr[idx]) take = helper(arr,sum-arr[idx],idx-1);
        return dp[idx][sum] = take + notTake;
    }
    int subsetSumEqualsK(vector<int>& arr, int sum) {
        dp.clear();
        dp.assign(arr.size(),vector<int>(sum+1,-1));
        return helper(arr,sum,arr.size()-1);
    }
  public:
    int perfectSum(vector<int>& arr, int target) {
        return subsetSumEqualsK(arr,target);
    }
};
//tabulation
class Solution {
  public:
    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<int>> dp;
        dp.clear();
        dp.assign(n,vector<int>(target+1,0));
        
        // base case
        // if target == 0  => whatever is the value of i don't care
        // Base case for the first element (row 0)
        if (arr[0] == 0) {
            dp[0][0] = 2; // We can pick 0 or skip 0; both yield a sum of 0
        } else {
            dp[0][0] = 1; // Only option is to skip it
            if (arr[0] <= target) { 
                dp[0][arr[0]] = 1; // Option to pick it
            }
        }
        for(int i = 1 ; i<n ;i++){
            for(int k = 0 ; k<=target ; k++){
                int notTake = dp[i-1][k];
                int take = 0;
                if(  arr[i] <= k ) take = dp[i-1][k - arr[i]];
                dp[i][k] = take + notTake;
            }
        }
        return dp[n-1][target];
    }
};