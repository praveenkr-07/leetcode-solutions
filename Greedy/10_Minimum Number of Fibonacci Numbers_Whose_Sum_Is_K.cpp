class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        if(k==1) return 1;
        vector<int> fibo;
        fibo.push_back(1); fibo.push_back(1);
        while(fibo.back() < k){
            fibo.push_back(fibo[fibo.size()-1]+fibo[fibo.size()-2]);
            if(fibo.back()==k){
                return 1;
            }
        }

        int n = fibo.size();
        int idx = n-2;
        int remaining = k - fibo[idx];
        int count = 1;
        idx--;

        while(idx >= 0){
            if(fibo[idx] <= remaining)   {
                count++;
                remaining -= fibo[idx];
                if(remaining==0) break;
            }
            idx--;
        }
        return count;
    }
};