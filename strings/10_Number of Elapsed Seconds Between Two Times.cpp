class Solution
{
public:
  int secondsBetweenTimes(string startTime, string endTime)
  {
    int startHour = stoi(startTime.substr(0, 2));
    int startMin = stoi(startTime.substr(3, 2));
    int startSec = stoi(startTime.substr(6, 2));
    int endHour = stoi(endTime.substr(0, 2));
    int endMin = stoi(endTime.substr(3, 2));
    int endSec = stoi(endTime.substr(6, 2));

    int startSecs = (startHour * 3600) + (startMin * 60) + startSec;
    int EndSecs = (endHour * 3600) + (endMin * 60) + endSec;

    return abs(startSecs - EndSecs);
  }
};
