class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;

        priority_queue< pair<int , vector<int> > > max_pq;

        for(auto i : points ){
            int dist =  i[0]*i[0] + i[1]*i[1] ;
            max_pq.push({dist , i});
            if(max_pq.size()>k) max_pq.pop();
        }
        
        while(!max_pq.empty()){
            ans.push_back(max_pq.top().second);
            max_pq.pop();
        }
        return ans;
    }
};