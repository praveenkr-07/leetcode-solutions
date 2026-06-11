class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> ans;
        
        priority_queue<int, vector<int>, greater<int>> min_pq;

        for(int i = 0 ;i<n ;i++){
            min_pq.push(arr[i]);
            if(min_pq.size() > k) {
                ans.push_back(min_pq.top());
                min_pq.pop();
            }
        }
        while(min_pq.size() > 0){
            ans.push_back(min_pq.top());
            min_pq.pop();
        }
        for(int i = 0 ;i<n ;i++) arr[i] = ans[i];
    }
};