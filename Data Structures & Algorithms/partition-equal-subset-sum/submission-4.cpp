class Solution {
public:

    bool canpartion(int ind,int target,vector<int>& nums,vector<vector<int>>&dp){
        if(ind==nums.size()){
            if(target==0){
                return true;
            }
            return false;
        }
        if(dp[ind][target]!=-1){return dp[ind][target];}

        //nottake
        int nottake = canpartion(ind+1,target,nums,dp);
        //take
        bool take=false;
        if(target-nums[ind]>=0)
            take= canpartion(ind+1,target-nums[ind],nums,dp);

        return dp[ind][target]= take || nottake;

    }

    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        vector<vector<int>>dp(nums.size(), vector<int>(sum/2+1,-1) );
        if(sum&1){return false;}

        return canpartion(0,sum/2,nums,dp);

    }
};
