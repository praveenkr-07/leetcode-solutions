class Solution {
public:
    int removeElement(vector<int>& arr, int val) {
        int n  = arr.size();
        int i = 0;
        int j = 0;
        while(j<n && i<n){

            while(j<n && arr[j]== val) j++;

            if(j<n){
            swap(arr[i],arr[j]);
            j++;
            i++;
            }
        }
        return i;
    }
};