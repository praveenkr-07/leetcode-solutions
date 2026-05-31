// Example 1:

// Input: s = "anagram", t = "nagaram"

// Output: true

// Example 2:

// Input: s = "rat", t = "car"

// Output: false 


// solution 1
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin() , s.end());
        sort(t.begin() , t.end());
        if(s==t) return true;
        else return false;
    }
};

// solution 2 
class Solution {
public:
    bool isAnagram(string s1, string s2) {
        if(s1.length()!=s2.length()) return false;
        unordered_map<char,int> m;

        for(char c : s1) m[c]++;
        
        for(char ch : s2){
            if(m.find(ch)!=m.end()){
                m[ch]--;
                if(m[ch]==0) m.erase(ch);
            }
            else return false;
        }
        return true;
    }
};