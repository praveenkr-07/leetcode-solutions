class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > min_pq;
        for(int i = 0 ; i<n ; i++){
            min_pq.push({arr[i],i});
        }

        int prev = INT_MIN;
        int rank = 0;
        vector<int> ranks(n);
        while(! min_pq.empty()){
            auto top = min_pq.top(); min_pq.pop();
            if(prev != top.first){
                prev = top.first;
                rank++;
            }
            ranks[top.second] = rank; 
        }
        return ranks;

    }
};