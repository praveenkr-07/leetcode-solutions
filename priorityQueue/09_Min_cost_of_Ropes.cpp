class Solution {
  public:
    int minCost(vector<int>& arr) {
        priority_queue<int,vector<int>,greater<int>> min_pq;
        for(auto i : arr) min_pq.push(i);
        int cost = 0;
        while(true){
            if(min_pq.size()==1) break;
            int len1 = min_pq.top(); min_pq.pop();
            int len2 = min_pq.top(); min_pq.pop();
            cost+=len1+len2;
            min_pq.push(len1+len2);
        }
        return  cost;
    }
};