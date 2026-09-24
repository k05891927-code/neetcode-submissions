class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        for(auto it:nums){
            m[it]++;
        }
        vector<vector<int>>v;
        for(auto it:m){
            v.push_back({it.second,it.first}); //count, element
        }
        sort(v.begin(),v.end());
        vector<int>ans;
        for(int i=0;i<k;i++){
            ans.push_back(v[v.size()-1- i][1]);
        }
        return ans;
    }
};
