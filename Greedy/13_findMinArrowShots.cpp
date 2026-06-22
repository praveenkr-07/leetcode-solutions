class Solution {
    static bool cmp(vector<int>&a , vector<int>&b){
        return a[1] < b[1];
    }
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),cmp);
        int n = points.size();
        int PrevLast = points[0][1];
        int nonOverlap = 0;
        for(int k = 1 ;k<n ;k++){
            int currStart = points[k][0];
            if(currStart <= PrevLast) nonOverlap++;
            else PrevLast = points[k][1];
        }
        return n-nonOverlap ;
    }
};