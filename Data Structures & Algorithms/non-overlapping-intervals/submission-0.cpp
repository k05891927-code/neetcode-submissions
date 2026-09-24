bool comp(vector<int>&a,vector<int>&b){
    return a[1]<b[1];
}

class Solution {
public:

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),comp);//sort on basis of end time

        vector<vector<int>>ans;

        int i=0;int n=intervals.size();

        while(i<n){
            if(ans.size()==0 || ans.back()[1]<=intervals[i][0]){
                ans.push_back(intervals[i]);
            }
            i++;
        }
        return n-ans.size();

    }
};
