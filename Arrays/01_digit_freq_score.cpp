// Example 1:

// Input: n = 122

// Output: 5

// Explanation:

// The digit 1 appears 1 time, contributing 1 * 1 = 1.
// The digit 2 appears 2 times, contributing 2 * 2 = 4.
// Thus, the score of n is 1 + 4 = 5.
// Example 2:

// Input: n = 101

// Output: 2

// Explanation:

// The digit 0 appears 1 time, contributing 0 * 1 = 0.
// The digit 1 appears 2 times, contributing 1 * 2 = 2.
// Thus, the score of n is 2.

class Solution {
public:
    int digitFrequencyScore(int n) {
        unordered_map<int,int> mp;
        int num = n;
        while(num>0){
            int rem = num%10;
            mp[rem]++;
            num=num/10;
        }
        
        int ans = 0;
        for(auto elem : mp){
            ans+=elem.first * elem.second;
        }
        return ans;
    }
};