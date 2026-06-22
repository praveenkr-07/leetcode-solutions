class Solution {
    static bool cmp(vector<int>&a , vector<int>&b ){
        return a[1]<b[1];
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        sort(intervals.begin(),intervals.end(),cmp);

        int n = intervals.size();

        int ans = 0;
        
        int lastTimePrev = intervals[0][1];
        for(int k = 1 ; k < n ; k++){
            if(intervals[k][0] < lastTimePrev) {
                ans++;
            }
            else{
                lastTimePrev = intervals[k][1];
            }
        }
        return ans;
    }
};