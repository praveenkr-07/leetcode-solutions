class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        priority_queue<int, vector<int>, greater<int>> min_pq(nums.begin(), nums.end()); // O(N) heapify


        for(auto ele : nums)  sum+=ele;
           
        while(k>=1){

            int minm =  min_pq.top();

            if(minm == 0) break;

            if(minm > 0){
                if(k % 2 != 0){
                    sum -= 2*minm;
                }
                break;
            }
            
            min_pq.pop();
            sum -= 2*minm;
            min_pq.push(-(minm));
            k--;
        }
        return sum;         
    }
};