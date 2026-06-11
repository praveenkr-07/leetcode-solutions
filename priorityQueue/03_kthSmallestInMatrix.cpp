class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        // T.C. = O(n^2)
        int n = matrix.size();
        priority_queue<int> max_pq;
        for(int i = 0 ; i< n ; i++){
            for(int j = 0 ; j<n ; j++){
                max_pq.push(matrix[i][j]);
                if(max_pq.size()>k){
                    max_pq.pop();
                }
            }
        }
        return max_pq.top();
    }
};