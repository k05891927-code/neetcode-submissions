class Solution {
public:
    unordered_map<string,vector<string>> adj;
    vector<string>ans;
    int total_edges=0;

    bool dfs(string node){
        

        if(ans.size()==total_edges+1){
            return true;
        }


        int nei_s = adj[node].size();
        for(int i=0;i<nei_s;i++){
            ans.push_back(adj[node][i]);
            string nei = adj[node][i];
            adj[node].erase(adj[node].begin() + i);
            if(dfs(nei)){
                return true;
            }
            ans.pop_back();
            adj[node].insert(adj[node].begin() + i, nei);

        }

        return false;
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        sort(tickets.begin(),tickets.end());
        total_edges= tickets.size();


        for(auto it:tickets){
            adj[it[0]].push_back( it[1] );
        }
        ans.push_back("JFK");
        dfs("JFK");
        return ans;
    }
};
