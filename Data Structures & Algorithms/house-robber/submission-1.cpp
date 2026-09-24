class Solution {
public:

    int solve(int ind,vector<int>&nums,vector<int>&dp){
        if(ind>=nums.size()){
            return 0;
        }
        if(dp[ind]!=-1){return dp[ind];}

        int nottake= solve(ind+1,nums,dp);
        int take= nums[ind]+ solve(ind+2,nums,dp);

        return dp[ind]= max(nottake,take);


    }


    int rob(vector<int>& nums) {
        vector<int>dp(nums.size()+2,-1);
        int ans=solve(0,nums,dp);
        return ans;

    }
};
