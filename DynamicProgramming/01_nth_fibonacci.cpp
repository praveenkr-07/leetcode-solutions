// Pure Recursion => Brute Force
class Solution {
public:
    int fib(int n) {
        if(n==0 || n==1) return n;
        return fib(n-1) + fib(n-2);
    }
};

// DP optimization => Tabular - Bottom Up Approach with Linear space
class Solution {
public:
    int fib(int n) {
        if(n==0 || n==1 ) return n;
        vector<int> dp(n+1);
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 2 ; i <= n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};
// DP optimization => Tabular - Bottom Up Approach with constant space
class Solution {
public:
    int fib(int n) {
        if(n==0 || n==1 ) return n;
        int a = 0;
        int b = 1;
        int c;
        int i = 2;
        while(i<=n){
            c = a+b;
            a = b;
            b = c;
            i++;
        }
        return c;
    }
};

// DP optimization => Memoization - top Down Approach with Linear space 
//0 <= n <= 30 
class Solution {
public:
    vector<int> dp = vector<int>(31, -1); 
    int fib(int n) {
        if(n==0 || n==1) return n;
        if(dp[n] != -1) return dp[n];
        return dp[n] = fib(n-1) + fib(n-2);
    }
};