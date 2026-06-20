class Solution {
  public:
    int minMeetingRooms(vector<int> &start, vector<int> &end) {
        
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        int i = 0;
        int j = 0;
        int rooms = 0;
        int minRooms = 0;
        while(i<start.size() && j<end.size()){
            if(start[i]<end[j]){
                rooms++;
                minRooms = max(rooms,minRooms);
                i++;
            }
            else if(start[i]==end[j]){
                i++;
                j++;
            }
            else{
                rooms--;
                j++;
            }
        }
        return minRooms;
        
    }
};
