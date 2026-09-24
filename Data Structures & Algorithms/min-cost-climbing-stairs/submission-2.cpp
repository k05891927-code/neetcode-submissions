class Solution {
public:

    int solve(int ind,vector<int>& cost,vector<int>&dp){
        if(ind>=cost.size()){
            return 0;
        }
        if(dp[ind]!=-1){return dp[ind];}
        int jump1= solve(ind+1,cost,dp);
        int jump2= solve(ind+2,cost,dp);

        return dp[ind]= cost[ind]+ min(jump1,jump2); 

    }

    int minCostClimbingStairs(vector<int>& cost) {
        // vector<int>dp(cost.size()+2,-1);
        // int st0 =solve(0,cost,dp);
        // int st1 =solve(1,cost,dp);
        // return min(st0,st1);

        vector<int>dp(cost.size()+2,0);

        for(int ind=n-1,ind>=0;ind--){
            int jump1= dp[ind+1];
            int jump2= dp[ind+2];
            dp[ind]= cost[ind]+ min(jump1,jump2);
        }
        return min(dp[0],dp[1]);

    }
};
