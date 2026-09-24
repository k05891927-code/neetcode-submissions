class Solution {
public:

    int solve(int stind, int end, vector<int>&nums,vector<vector<int>>&dp){
        if(stind>end){
            return 0;
        }
        if(dp[stind][end]!=-1){return dp[stind][end];}

        //nottake
        int nottake= solve(stind+1,end,nums,dp);
        //take
        int take = nums[stind]+ solve(stind+2,end,nums,dp);

        return  dp[stind][end]= max(nottake,take);

    }

    int rob(vector<int>& nums) {
        

        int n=nums.size();
        vector<vector<int>>dp1(nums.size(),vector<int>(nums.size(),-1));
        int include1 = solve(0,n-2,nums,dp1);
        vector<vector<int>>dp2(nums.size(),vector<int>(nums.size(),-1));
        int include2= solve(1,n-1,nums,dp2);

        return max(include1,include2);

    }
};
