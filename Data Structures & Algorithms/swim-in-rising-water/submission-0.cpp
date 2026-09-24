class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<pair<int,int> ,vector<pair<int,int>>,greater<pair<int,int>> >pq;
        int r= grid.size(),c= grid[0].size();
    
        int node=0;
        int nr= node/c, nc=node%r;
        int height= grid[nr][nc];
        pq.push({height,node});
        
        ///////
        vector<vector<int>>nei = {{0,1},{0,-1},{-1,0},{1,0}};
        while(!pq.empty()){
            int hei= pq.top().first;
            int nod= pq.top().second;
            int curr=nod/c,curc=nod%r; 

            if(nod==c*r-1){
                return hei;
            }

            for(auto ne:nei){
                int nr=curr+ne[0],nc=curc+ne[1];
                if(nr>=0 && nr<r && nc>=0 && nc<c){
                    //access grid
                    pq.push({max(grid[curr][curc],grid[nr][nc]),ne[0]*c+ne[1]*r} );

                }
            }

        }
        return  -1;

    }
};
