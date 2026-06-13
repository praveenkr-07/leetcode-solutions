class KthLargest {
public:
    int k ;
    priority_queue<int , vector<int> , greater<int> >min_pq;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(auto i : nums) {
            add(i);
        }
    }
    
    int add(int val) {
        min_pq.push(val);
            if(min_pq.size()>k) min_pq.pop();
            return min_pq.top();
        }
};
