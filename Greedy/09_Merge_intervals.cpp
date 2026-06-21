class Solution {
    static bool cmp(vector<int>&a , vector<int>&b){
        return a[1] < b[1];
    }
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end(),cmp);
        vector<vector<int>> result;
        result.push_back(intervals[n-1]);
        for(int i = n-2 ; i>= 0 ; i--){
            vector<int> curr = intervals[i];
            if(curr[1] >= result[result.size()-1][0]){
                result[result.size()-1][0] = min(curr[0],result[result.size()-1][0]);
                result[result.size()-1][1] = max(curr[1],result[result.size()-1][1]);
            }else{
                result.push_back(intervals[i]);
            }
        }
        return result;
    }
};