class Solution {
public:

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<float,vector<int>> >pq;//use max heap with k size or min heap with all elemnets
        for(auto it:points){
            float dis= sqrt(it[0]*it[0]+ it[1]*it[1]);
            pq.push({dis,it});
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<vector<int>>ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
