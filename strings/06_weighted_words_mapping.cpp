class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        int n  = words.size();
        string ans = "";
        for(int i = 0 ;i<words.size();i++){
            int wt = 0;
            for(int  j = 0 ;j<words[i].length();j++){
                int asc = int(words[i][j]);
                wt += weights[asc % 97 ];
            }
            wt = wt % 26;
            ans += char(122-wt);
        }
        return ans;
    }
};