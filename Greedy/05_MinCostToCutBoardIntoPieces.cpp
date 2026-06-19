class Solution {
    static bool cmp(int a , int b){
        return a > b ;
    }
  public:
    int minCost(int n, int m, vector<int>& vertical, vector<int>& horizontal) {
        sort(vertical.begin(),vertical.end(),cmp);
        sort(horizontal.begin(),horizontal.end(),cmp);
        
        // intitially 
        int hz = 1; // no. of horizontal cuts 
        int vr = 1; // no. of vertical cuts 
        int minCost = 0;
        
        // pointers => to iterate both arrays
        int h = 0 ; //  for horizontal[]
        int v = 0 ; //  for vertical[]
        
        while(v < vertical.size() && h < horizontal.size()){
            if( vertical[v] >= horizontal[h] ){
                minCost += vertical[v]*vr;
                v++;
                hz++;
            }
            else{
                minCost += horizontal[h]*hz;
                h++;
                vr++;   
            }
        }
        while(v<vertical.size()){
            minCost += vertical[v]*vr;
            v++;
        }
        while(h < horizontal.size()){
            minCost +=  horizontal[h]*hz;
            h++;
        }
        return minCost;
        // Time Complexity = O(nlogn + mlogm)
        // Space Complexity = O(1)
    }
};
