class Solution {
public:
    void dfs(int node, vector<int>&vis,vector<int> adj[]){
        vis[node]=1;

        for(auto it:adj[node]){
            if(vis[it]==0){
                dfs(it,vis,adj);
            }
        }

    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int>vis(n,0);int cnt=0;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                dfs(i,vis,adj);
                cnt++;
            }
        }

        return cnt;

    }
};
