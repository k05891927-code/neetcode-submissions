class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>ans;

        int st=0;int n=intervals.size();

        while(st<n && intervals[st][1]<newInterval[0]){
            ans.push_back(intervals[st]);
            st++;
        }

        int flag=1;
        vector<int>overla={newInterval[0],newInterval[1]};
        while(st<n && newInterval[1]>=intervals[st][0]){
            overla[0]= min(intervals[st][0],overla[0]);
            overla[1]= max(intervals[st][1],overla[1]);
            st++;
        }
        ans.push_back(overla);

        while(st<n){
            ans.push_back(intervals[st]);
            st++;
        }
        return ans;


    }
};
