// Brute force
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int ans = 0;
        for(int j = 0; j<n;j++){
            unordered_map<char,int> mp;
            for(int i = j ;i<n;i++){
            mp[s[i]]++;
            if (mp.find('a') != mp.end() && mp.find('b') != mp.end() && mp.find('c') != mp.end()) {
                ans += n-i;
                break;
            }
            }
        }
        return ans;
    }
};


// Optimal Solution
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int ans = 0;
        // 'a' => 0 , 'b' => 1 , 'c' => 2
        int arr[3] = {-1,-1,-1};
        for(int i = 0; i<n;i++){
            arr[s[i]-'a'] = i;
            if(arr[0] != -1 && arr[1] != -1 && arr[2] != -1  ){
                ans += min(arr[0],min(arr[1],arr[2])) + 1;
            }
        }
        return ans;
    }
};