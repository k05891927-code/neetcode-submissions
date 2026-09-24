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

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int>start,end;

        for(auto it:intervals){
            start.push_back(it.start);
            end.push_back(it.end);
        }
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());

        int time=0;
        int stind=0;int enind=0;

        int room=0;
        int maxroom=0;

        while(stind<start.size()){

            time=min(start[stind]+1,end[enind]+1);//i cant really take desicion at start, but at start+1 about new room

            while(stind<start.size() && start[stind]<time){
                stind++;
                room++;
            }
            while(enind<start.size() && end[enind]<time){
                enind++;
                room--;
            }
            maxroom=max(maxroom,room);
        }

        return maxroom;
    }
};
