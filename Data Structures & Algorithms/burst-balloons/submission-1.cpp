class Solution {
public:

    int solve(int st,int en, vector<int>&nums,vector<vector<int>>&dp){
        if(st>en){
            return 0;
        }
        if(dp[st][en]!=-1){return dp[st][en];}
        int ans=0;
        for(int k=st;k<=en;k++){
            int curans= nums[st-1]*nums[k]*nums[en+1]+solve(st,k-1,nums,dp)+solve(k+1,en,nums,dp);
            ans=max(ans,curans);
        }
        return dp[st][en]=ans;


    }

    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.insert(nums.end(),1);

        int size=nums.size();
        vector<vector<int>>dp(size,vector<int>(size,-1));

        int ans=solve(1,nums.size()-2,nums,dp);
        return ans;

    }
};
