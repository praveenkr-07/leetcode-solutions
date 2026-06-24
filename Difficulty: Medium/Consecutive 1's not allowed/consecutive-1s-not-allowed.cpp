class Solution {
  public:
    int countStrings(int n) {
        if(n==1 || n ==2) return n+1;
        int a = 2;
        int b = 3;
        int c ;
        for(int i = 3; i<=n ; i++ ){
            c = a+b;
            a =b;
            b=c;
        }
        return c;
    }
};