
#define land 2147483647
class Solution {
public:

    void findSd(int i,int j,vector<vector<int>>& grid){

        vector<vector<int>>nei={{1,0},{-1,0},{0,1},{0,-1}};

        queue<vector<int>>q;
        q.push({0,i,j});

        while(!q.empty()){
            auto fr= q.front();
            q.pop();

            for(auto it:nei){
                int cr = fr[1]+it[0],cc =fr[2]+it[1];
                if(cr<0 || cr>= grid.size() || cc<0 || cc>= grid[0].size() || grid[cr][cc]==-1 || grid[cr][cc]==0){continue;}

                if(grid[cr][cc]>fr[0]+1){
                    grid[cr][cc]=fr[0]+1;
                    q.push({grid[cr][cc], cr,cc});
                }
            }
        }
    }

    void islandsAndTreasure(vector<vector<int>>& grid) {
        
        int r= grid.size();
        int c= grid[0].size();

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==0)
                    findSd(i,j,grid); //update shortest distance with trasure
            }
        }

    }
};
