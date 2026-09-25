class Solution {
public:

    int solve(int ind,int buy,vector<int>& prices,vector<vector<int>>&dp){
        if(ind>=prices.size()){return 0;}

        if(dp[ind][buy]!=-1){return dp[ind][buy];}
        if(buy){
            int take= -prices[ind]+ solve(ind+1,0,prices,dp);
            int donttake= 0 + solve(ind+1,1,prices,dp);
            return dp[ind][buy]=max(take,donttake);
        }
        if(!buy){//sell
            int sell = prices[ind]+ solve(ind+2,1,prices,dp);
            int hold = 0 +   solve(ind+1,0,prices,dp);
            return dp[ind][buy]=max(sell,hold);
        }
        return 0; //dummy return 

    }

    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        int ans=solve(0,1,prices,dp);//ind,buy,array
        return ans;
    }
};
