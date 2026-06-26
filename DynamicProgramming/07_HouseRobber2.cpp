class Solution {
    int rob1(vector<int>& nums) {
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
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        vector<int> temp1;
        vector<int> temp2;
        for(int i = 0;i<n;i++){
            if(i!=0)  temp1.push_back(nums[i]);
            if(i!=n-1)temp2.push_back(nums[i]);
        }
        return max (rob1(temp1),rob1(temp2));
    }
};