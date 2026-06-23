https://www.geeksforgeeks.org/problems/geek-jump/1
// Pure Brute Forece solution 
class Solution {
    int helper(int k , vector<int>& height , int idx){
        if(idx == height.size()-1) return 0;
        
        int total_min_cost = INT_MAX;
        
        for(int jump = 1; jump<= k; jump++){
            int next_index = jump+idx;
            if(next_index < height.size()){
                int jump_cost = abs(height[idx]-height[next_index]);
                int total_cost = jump_cost + helper(k,height,next_index);
                total_min_cost = min(total_min_cost,total_cost);
            }
        }
       return total_min_cost;
    }
  public:
    int index = 0;
    int minCost(vector<int>& height) {
        return helper(2,height,0);
    }
}; 


// optimized with memoization / top down 
class Solution {
    vector<int> dp;
    int helper(int k , vector<int>& height , int idx){
        dp.resize(height.size()+100 , -1);
        if(idx == height.size()-1) return 0;
        
        if(dp[idx]!=-1) return dp[idx];
        
        int total_min_cost = INT_MAX;
        
        for(int jump = 1; jump<= k; jump++){
            int next_index = jump+idx;
            if(next_index < height.size()){
                int jump_cost = abs(height[idx]-height[next_index]);
                int total_cost = jump_cost + helper(k,height,next_index);
                total_min_cost = min(total_min_cost,total_cost);
            }
        }
       return dp[idx] = total_min_cost;
    }
  public:
    int index = 0;
    int minCost(vector<int>& height) {
        return helper(2,height,0);
    }
}; 

//optimized with Tabularization / bottom Up
class Solution {
  public:
    int minCost(vector<int>& height) {
        int n = height.size();
        vector<int> dp;
        dp.resize(n , INT_MAX);
        dp[n-1]=0;
        for(int i = n-2 ; i >=0 ; i--){
            for(int j = 1 ;j<= k ; j++){
                if( i+j < n){
                    dp[i] = min(dp[i],abs(height[i]-height[i+j]) + dp[i+j]);
                }
            }
        }
        return dp[0];
    }
}; 
