// LC 386
class Solution {
    void helper(int n , vector<int>&lexicoSorted,int i){
        if(i>n) return;
        if(i!=0) lexicoSorted.push_back(i);
        if(i!=0){
            for(int j = 0 ;j<= 9; j++){
                helper(n,lexicoSorted,10*i+j);
            }
        }else{
            for(int j = 1 ;j<= 9; j++){
                helper(n,lexicoSorted,10*i+j);
            }
        }
    }
public:
    vector<int> lexicalOrder(int n) {
        vector<int> lexicoSorted;
        helper(n , lexicoSorted , 0 );
        return lexicoSorted;
    }
};