class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int , vector<int> , greater<int> > min_pq;
        for(int  i = 0;i<n;i++){
            min_pq.push(nums[i]);
            if (min_pq.size()>k)  min_pq.pop();
        }
        return min_pq.top();
    }
};