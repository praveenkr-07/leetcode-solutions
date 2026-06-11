class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n  = nums.size();
        
        unordered_map<int,int> mp;
        for(auto i : nums) mp[i]++;

        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > min_pq;

        for(auto ele : mp){
            pair<int,int> p;
            p.first = ele.second;
            p.second =  ele.first;
            min_pq.push(p);
            if(min_pq.size() > k) min_pq.pop();
        }
        vector<int> ans;
        while(!min_pq.empty()){
            pair<int,int> p = min_pq.top();
            min_pq.pop();
            ans.push_back(p.second);
        }
            return ans;
    }
};