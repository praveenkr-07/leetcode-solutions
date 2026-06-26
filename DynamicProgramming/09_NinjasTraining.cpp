// https://www.geeksforgeeks.org/problems/geeks-training/1
class Solution {
    vector<vector<int>> dp;
    int helper(vector<vector<int>>& mat,int day , int lastTask){
        if (dp[day][lastTask] != -1) return dp[day][lastTask];
        // base case 
        if(day == 0){
            int ptsOfday1 = 0;
            for(int i = 0 ;i<3 ; i++){
                if(i != lastTask){
                    ptsOfday1 = max(ptsOfday1,mat[0][i]);
                }
            }
            return dp[day][lastTask] = ptsOfday1;
        }
        
        int totalPts = 0;
        for(int i = 0 ;i<3 ; i++){
                if(i != lastTask){
                    int pts = mat[day][i] + helper(mat,day-1,i);
                    totalPts = max(totalPts,pts);
                }
            }
            return dp[day][lastTask] = totalPts;
        
    }
  public:
    int maximumPoints(vector<vector<int>>& mat) {
        dp.clear();
        dp.assign(mat.size(), vector<int>(4, -1));
        return helper(mat,mat.size()-1,3); 
    }
};