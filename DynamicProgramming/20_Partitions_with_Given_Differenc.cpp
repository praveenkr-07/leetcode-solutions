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
    int countPartitions(vector<int>& arr, int diff) {
        int n = arr.size();
        int totalSum = 0;
        for(int i = 0 ;i<n ; i++) totalSum += arr[i];
        if( (totalSum - diff) % 2 != 0 || (totalSum - diff) < 0) return 0;
        int sum = (totalSum - diff)/2 ;
        dp.clear();
        dp.assign(n,vector<int>(sum+1,-1));
        return subsetSumEqualsK(arr,sum);
    }
};