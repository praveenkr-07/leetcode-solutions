class Solution {
    static bool cmp(pair<int,int>&p1 , pair<int,int>p2){
        // first -> val , second-> wt
        double r1 = (p1.first*1.0) / (p1.second*1.0);
        double r2 = (p2.first*1.0) / (p2.second*1.0);
        return r1>r2;
    }
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int w) {
        
        int n = val.size();
        
        vector<pair<int,int> > frac;
        
        for(int i = 0; i<n ; i++){
            frac.push_back({val[i],wt[i]});
        }
        
        sort(frac.begin() , frac.end() , cmp);
        
        double result = 0;
        for(int i = 0; i<n ; i++){
            if(frac[i].second<= w){
                result += frac[i].first;
                w -= frac[i].second;
            }
            else{
                result += ((frac[i].first)*1.0 / frac[i].second*1.0 )*w;
                w = 0;
                break;
            }
        }
        return result;
    }
};
