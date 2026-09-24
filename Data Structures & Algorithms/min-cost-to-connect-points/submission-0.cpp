class Solution {
public:
    int manh(int x1,int y1,int x2,int y2){
        return abs(x1-x2)+abs(y1-y2);
    }

    int par(int node,vector<int>&parent){
        if(parent[node]==node){
            return node;
        }
        return parent[node]=par(parent[node],parent);
    }

    bool dsu_union(int i,int j,vector<int>&parent,vector<int>&siz){
        int par1=par(i,parent);
        int par2=par(j,parent);
        
        if(par1==par2){
            return false;
        }

        if(siz[par1]<=siz[par2]){
            siz[par2]+=siz[par1];
            parent[par1]=par2;
        }
        else{
            siz[par1]+=siz[par2];
            parent[par2]=par1;
        }
        return true;
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<int>>dis;
        for(int i=0;i<points.size();i++){
            for(int j=0;j<points.size();j++){
                if(i<j){
                    int man_distance=manh(points[i][0],points[i][1],points[j][0],points[j][1]);
                    dis.push_back({man_distance,i,j});
                }
            }
        }
        sort(dis.begin(),dis.end());

        //DSU
        vector<int>parent(points.size(),0),siz(points.size(),0);
        for(int i=0;i<points.size();i++){
            parent[i]=i;
            siz[i]=1;
        }
        int tot_cost=0;
        for(auto it:dis){
            bool u=dsu_union(it[1],it[2],parent,siz);
            if(u){ //different parent
                tot_cost+=it[0];
            }
        }
        return tot_cost;
    }
};
