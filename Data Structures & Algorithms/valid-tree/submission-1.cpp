class Solution {
public:

    bool dfs(int parent,int node, vector<int>&vis,vector<int>adj[]){
        vis[node]=1;

        for(auto it:adj[node]){
            if(it==parent)
                continue;
            else if(vis[it]==0){
                bool isw= dfs(node,it,vis,adj);
                if(isw){
                    return true;
                }
            }
            else if(vis[it]==1 )
                return true;
        }
        return false;

    }

    bool validTree(int n, vector<vector<int>>& edges) {

        vector<int>vis(n,0),adj[n];

        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        return !dfs(-1, 0,vis,adj);

    }
};
