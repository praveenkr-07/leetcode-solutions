// Recursion Only
class Solution {
  public:
    bool helper(vector<int>& arr, int sum , int idx){
        if(sum==0) return true;
        if(idx==0) return arr[0] == sum ;
        bool notTake = helper(arr,sum,idx-1);
        bool take = false;
        if(sum >= arr[idx]) take = helper(arr,sum-arr[idx],idx-1);
        return take || notTake;
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        return helper(arr,sum,arr.size()-1);
    }
};

//Memoized
class Solution {
  public:
    vector<vector<int>> dp;
    bool helper(vector<int>& arr, int sum , int idx){
        if(sum==0) return true;
        if(idx==0) return arr[0] == sum ;
        if(dp[idx][sum] != -1) return dp[idx][sum];
        bool notTake = helper(arr,sum,idx-1);
        bool take = false;
        if(sum >= arr[idx]) take = helper(arr,sum-arr[idx],idx-1);
        return dp[idx][sum] = (take || notTake);
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        dp.clear();
        dp.assign(arr.size(),vector<int>(sum+1,-1));
        return helper(arr,sum,arr.size()-1);
    }
};

// Tabulation
class Solution {
  public:
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
};