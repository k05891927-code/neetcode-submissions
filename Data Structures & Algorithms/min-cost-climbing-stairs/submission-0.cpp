class Solution {
public:

    int solve(int ind,vector<int>& cost){
        if(ind>=cost.size()){
            return 0;
        }

        int jump1= solve(ind+1,cost);
        int jump2= solve(ind+2,cost);

        return cost[ind]+ min(jump1,jump2); 

    }

    int minCostClimbingStairs(vector<int>& cost) {
        
        int st0 =solve(0,cost);
        int st1 =solve(1,cost);
 

        return min(st0,st1);
    }
};
