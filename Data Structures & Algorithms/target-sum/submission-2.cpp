class Solution {
public:
    int totsum;

    int solve(int ind,int cursum,int target,vector<int>& nums,vector<vector<int>>&dp){
        if(ind==nums.size()){
            if(cursum==target){
                return 1;
            }
            else{
                return -1;//way no exist
            }
        }
        if(dp[ind][totsum+cursum]!=-1){return dp[ind][totsum+cursum];}
        //positive
        int pos = solve(ind+1,cursum+nums[ind],target,nums,dp);
        //negative
        int neg= solve(ind+1, cursum-nums[ind],target,nums,dp);

        int ans=0;
        if(pos!=-1){ans+=pos;}
        if(neg!=-1){ans+=neg;}
        return dp[ind][totsum+cursum]=ans;


    }

    int findTargetSumWays(vector<int>& nums, int target) {
        totsum= accumulate(nums.begin(),nums.end(),0);
        vector<vector<int>>dp(nums.size(), vector<int>(2*totsum+1,-1));
        int ans=solve(0,0,target,nums,dp);
        return ans!=-1? ans : 0;
    }
};
