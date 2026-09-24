/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

bool comp(Interval &a, Interval &b){
    return (a.end) < (b.end);
}


class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(),intervals.end(),comp);

        if(intervals.size()<=1){return true;}

        int curend=intervals[0].end;

        for(int i=1;i<intervals.size();i++){
            if(intervals[i].start<curend){
                return false;
            }
            curend=intervals[i].end;
        }
        return true;
    }
};
