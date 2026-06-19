class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {

        string ans ="";
        unordered_map<char,int> mp;
        for(int i=0;i<s.length();i++) mp[s[i]]++;

        priority_queue<pair<char,int>> max_pq;
        for(auto p : mp) max_pq.push(p);

        while(! max_pq.empty()){
            auto largest = max_pq.top(); max_pq.pop();

            int len = min(largest.second , repeatLimit);

            for(int i = 0;i<len;i++) ans += largest.first;

            pair<char,int> secondLargest;

            if(largest.second - len > 0) { // frequency of lexicographically largest > repeatLimit 
                // once append secondLargest in ans 
                if(!max_pq.empty()){
                    secondLargest = max_pq.top(); max_pq.pop();
                    ans += secondLargest.first;
                    // push the remaining secondLargest 
                    if( secondLargest.second > 1) max_pq.push({secondLargest.first , secondLargest.second -1});
                    // push remaining largest 
                    max_pq.push({largest.first , largest.second - len});
                }else{  // if there is no second largest also , the largest repeated thier repeatLimit times so there is no more possibility
                    return ans;
                }
            }
        }
        return ans;

    }
};