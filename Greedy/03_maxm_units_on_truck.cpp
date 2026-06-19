class Solution {
    static bool cmp(vector<int>& boxTypes1 ,vector<int>& boxTypes2){
        return boxTypes1[1]  > boxTypes2[1]; 
    }
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),cmp);
        int n = boxTypes.size();

        int result = 0;
        for(int i = 0;i<n ; i++){
            if(boxTypes[i][0] <= truckSize) {
                result += boxTypes[i][1] * boxTypes[i][0];
                truckSize -=  boxTypes[i][0];
            }
            else{
                result += truckSize * boxTypes[i][1];
                truckSize = 0;
                break;
            }
        }
        return result;
    }
};