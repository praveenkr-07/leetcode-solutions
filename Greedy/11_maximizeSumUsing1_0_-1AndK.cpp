class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        if(k <= numOnes ) return k;
        
        int ans = 0;
        ans += numOnes;
        k -= numOnes;
        k -= numZeros;

        if(k <= 0 || numNegOnes == 0) return ans;        

        // remaining k >= numNegOnes
        if(k >= numNegOnes){
            ans -= numNegOnes; 
            return ans;
        }

        // k < numNegOnes
        ans -= k; 
        return ans;
    }
};
// LeetCode = 2600
