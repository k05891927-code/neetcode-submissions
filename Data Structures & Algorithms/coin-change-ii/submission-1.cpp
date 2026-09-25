class Solution {
public:

    int solve(int ind,int amount,vector<int>& coins,vector<vector<int>>&dp){
        if(ind==0){
            if(amount%coins[0]==0){
                return 1;
            }
            else{
                return -1;//not possible to make amount
            }
        }
        if(dp[ind][amount]!=-1){return dp[ind][amount];}
        //nottake
        int nottake=  solve(ind-1,amount,coins,dp);
        int take=-1;
        if(amount>=coins[ind]){
            take= solve(ind,amount-coins[ind],coins,dp);
        }
        int ans=0;
        if(take!=-1){
            ans+=take;
        }
        if(nottake!=-1){
            ans+=nottake;
        }
        return dp[ind][amount]= ans;

    }

    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        int ans=solve(coins.size()-1,amount,coins,dp);
        return ans!=-1? ans : 0;
    }
};
