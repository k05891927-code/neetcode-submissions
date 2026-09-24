class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<int>dis(n,INT_MAX);
        dis[src]=0;

        vector<vector<pair<int,int>>>adj(n);

        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]}); //scr->{dst,wei}
        }

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>> >pq;
        // hop, distance , tonode
        pq.push({0,0,src});

        while(!pq.empty()){

            auto it= pq.top();

            int hopk=it[0],distance=it[1],node=it[2];

            pq.pop();
            if(it[0]>k){
                break;//reached more hops count
            }

            for(auto nei:adj[node]){
                int neinode=nei.first,edgew=nei.second;

                if(dis[neinode]> distance + edgew ){
                    pq.push({hopk+1,distance + edgew,neinode});
                    dis[neinode]= distance + edgew;
                    cout<<hopk+1<<" "<<distance + edgew<<" "<<neinode<<endl;
                }

            }

        }

        if(dis[dst]==INT_MAX){
            return -1;
        }
        return dis[dst];

    }
};
