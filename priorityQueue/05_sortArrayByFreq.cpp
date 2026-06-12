// Example 1:
// Input: nums = [1,1,2,2,2,3]
// Output: [3,1,1,2,2,2]
// Explanation: '3' has a frequency of 1, '1' has a frequency of 2, and '2' has a frequency of 3.

// Example 2:
// Input: nums = [2,3,1,3,2]
// Output: [1,3,3,2,2]
// Explanation: '2' and '3' both have a frequency of 2, so they are sorted in decreasing order.

// Example 3:
// Input: nums = [-1,1,-6,4,5,-6,1,4,1]
// Output: [5,-1,4,4,-6,-6,1,1,1]

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int,int> mp;
        for(auto i : nums) mp[i]++;

        // custom comparator 
        auto cmp = [](pair<int,int> a, pair<int,int> b) {
        if (a.first == b.first) return a.second < b.second;
        return a.first > b.first;
        };

        priority_queue<pair<int,int> , vector<pair<int,int>> , decltype(cmp) > min_pq;

        for (auto ele : mp) {
            min_pq.push({ele.second,ele.first});
        }

        int i = 0;
        while (!min_pq.empty()) {
            pair<int,int> p = min_pq.top(); min_pq.pop();
            while (p.first-- ) nums[i++] = p.second;
        }
        return nums;

    }
};

