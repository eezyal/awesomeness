/*
 * Given a vector of intervals (s,e) (s-start time e-end time)
 * which indicate start and end of a meeting.
 * Determinie how many minimum interview rooms are required to
 * avoid a clash
 * */

#include <iostream>
#include <vector>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval(int s, int e) : start(s), end(e) {};
    operator 
};

int intervalcompare(Interval i1, Interval i2)
{
    if (i1.start < i2.start)
        return 1;
    else if (i1.start == i2.start)
        return 0;
    else
        return -1;
}

class Solution {
public:
    int minMeetRooms(vector<Interval> intervals) {
        int count = 0, maxCount = 0;
        sort(intervals.begin(), intervals.end(), intervalcompare);

        for(auto i1: intervals) {
            count = 0;
            for(auto i2: intervals)
                if (i2.start < i1.end)
                    count++;
            maxCount = max(maxCount, count);
        }
        return maxCount;
    }
};

int main() {
    vector<Interval> intervals
}
