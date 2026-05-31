// Input: s = "the sky is blue"
// Output: "blue is sky the"


// solution 1
class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        string word;
        stringstream ss(s);

        while (ss >> word) {
            words.push_back(word);
        }
        s = "";

    
        for(int j = words.size()-1;  j >= 0 ; j--){
            s = s + words[j] + " ";
        }

        s.pop_back();
        return s;
    }
}; 

// solution 2
class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        reverse(s.begin(),s.end());
        int i = 0;
        int j = 0;
        while(j<n){
            while(j<n && s[j] != ' ') j++;
            reverse(s.begin()+i,s.begin()+j);
            while(j<n && s[j] == ' ') j++;
            i=j;
        }
        int write = 0;
        int read = 0;
        while(read<n){
            while(read<n && s[read]==' ') read++;
            while(read<n && s[read]!=' ') s[write++] = s[read++];
            while(read<n && s[read]==' ') read++;
            if(read<n){
                s[write++] = ' ';
            }
        }
        s.resize(write);

        return s;
    }
};