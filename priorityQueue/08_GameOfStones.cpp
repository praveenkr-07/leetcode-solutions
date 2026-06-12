class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> max_pq;
        for(auto i : stones ) max_pq.push(i);
        while(max_pq.size() != 1){
            int first = max_pq.top(); max_pq.pop();
            int second = max_pq.top(); max_pq.pop();
            if(first-second != 0) max_pq.push(abs(first-second));
            if(max_pq.size()==0) return 0;
        }
        return max_pq.top();
    }
};