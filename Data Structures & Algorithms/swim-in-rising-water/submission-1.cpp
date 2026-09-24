class Solution {
public:
    
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<pair<int,int> ,vector<pair<int,int>>,greater<pair<int,int>> >pq;
        int r= grid.size(),c= grid[0].size();

        vector<int>disv(r*c,INT_MAX);

        int node=0;
        int nr= node/c, nc=node%c;
        int height= grid[nr][nc];
        disv[node]=height;
        pq.push({height,node});
        
        ///////
        vector<vector<int>>nei = {{0,1},{0,-1},{-1,0},{1,0}};
        while(!pq.empty()){
            int hei= pq.top().first;
            int nod= pq.top().second;
            pq.pop();
            int curr=nod/c,curc=nod%c; 

            if(nod==c*r-1){
                return hei;
            }

            for(auto ne:nei){
                int nr=curr+ne[0],nc=curc+ne[1];
                if(nr>=0 && nr<r && nc>=0 && nc<c && max(hei,grid[nr][nc])<disv[nr*c+nc] ){
                    //access grid
                    pq.push({max(hei,grid[nr][nc]),nr*c+nc} );
                    disv[nr*c+nc]= max(hei,grid[nr][nc]);

                }
            }

        }
        return  -1;

    }
};
