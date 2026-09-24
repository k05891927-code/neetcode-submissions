class Solution {
public:

    int LIS(int ind,int prev, vector<int>& nums,vector<vector<int>>&dp){
        if(ind==nums.size()){
            return 0;
        }
        if(dp[ind][prev+1]!=-1){
            return dp[ind][prev+1];
        }
        //nottake
        int nottake= LIS(ind+1,prev,nums,dp);

        //take
        int take=INT_MIN;
        if(prev==-1 ||  nums[ind]>nums[prev])
            take=1+ LIS(ind+1,ind,nums,dp);

        return dp[ind][prev+1]=max(take,nottake);

    }

    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>>dp(nums.size(),vector<int>(nums.size()+1,-1));
        return LIS(0,-1,nums,dp);
    }
};
