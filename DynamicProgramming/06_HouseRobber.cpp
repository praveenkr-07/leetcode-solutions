class Solution {
    vector<int> dp;
    int helper(vector<int>& nums, int idx  ){
        if(idx >= nums.size()) return 0;
        if(idx == nums.size()-1) return nums[idx];
        if(idx == nums.size()-2) return max(nums[idx],nums[idx+1]);
        if (dp[idx] != -1) return dp[idx];
        return dp[idx] = max(nums[idx] + helper(nums, idx+2), helper(nums, idx+1));
    }
public:
    int rob(vector<int>& nums) {
        dp.resize(nums.size(),-1);
        return helper(nums,0);
    }
};

// Bottom - up
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        vector<int> dp;
        dp.resize(nums.size(),-1);
        dp[n-1] = nums[n-1];
        dp[n-2] = max(nums[n-2],nums[n-1]);
        for(int i = n-3 ;i >= 0 ;i--){
            dp[i] = max(dp[i+1],dp[i+2]+nums[i]);
        }
        return dp[0];
    }
};