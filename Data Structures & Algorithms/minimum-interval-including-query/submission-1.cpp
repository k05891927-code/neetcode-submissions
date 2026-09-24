class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        vector<int>cpyq(queries.begin(),queries.end());
        sort(queries.begin(),queries.end());
        sort(intervals.begin(),intervals.end());

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<>>pq;

        int includedtill=0;map<int,int>m;

        for(int qind=0;qind<queries.size();qind++){

            while(!pq.empty() && pq.top().second.second<queries[qind]){
                pq.pop();
            }
            while(includedtill<intervals.size() && intervals[includedtill][0]<=queries[qind]  ){
                int intvsize= intervals[includedtill][1]-intervals[includedtill][0]+1;
                pq.push({intvsize, {intervals[includedtill][0],intervals[includedtill][1]}});
                includedtill++;
            }
            while(!pq.empty() && pq.top().second.second<queries[qind]){
                pq.pop();
            }
            if(pq.empty()){
                m[queries[qind]]=-1;
            }
            else{
                m[queries[qind]] = pq.top().first;
            }
        }
        vector<int>ans;
        for(auto q:cpyq){
            ans.push_back(m[q]);
        }
        return ans;
    }
};
