class Solution
{
public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x)
    {
        vector<int> v;
        int n = arr.size();

        priority_queue<pair<int,int>> max_pq;

        for(auto ele : arr){
            int distance =  abs(ele-x);
            pair<int,int> p = {distance , ele};
            max_pq.push(p);
            if(max_pq.size()>k) max_pq.pop();
        }

        while(!max_pq.empty()){
            pair<int,int> pa = max_pq.top();  max_pq.pop();
            v.push_back(pa.second);
        }

        sort(v.begin(), v.end());
        return v;
    }
};