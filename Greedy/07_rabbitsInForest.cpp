class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int n = answers.size();
        unordered_map<int,int> mp;
        int ans = 0;
        for(int i = 0;i<n;i++) {
            int rabbits = answers[i];
            if(mp.find(rabbits) == mp.end()) ans += rabbits+1;
            mp[rabbits]++;
            if(mp[rabbits] == rabbits+1) mp.erase(rabbits);
        }
        return ans;
    }
};