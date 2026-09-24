class Solution {
public:

    int solve(int n,vector<int>&dp){
        if(n==0){
            return 1;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int step1= climbStairs(n-1);

        int step2=0;
        if(n>=2)
            step2= climbStairs(n-2);

        return dp[n]=step1+step2;
    }

    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        // return solve(n,dp);

        dp[0]=1;
        for(int i=1;i<=n;i++){
            int step1= dp[i-1];
            int step2=0;
            if(i>=2)
                step2= dp[i-2];
            
            dp[i]=step1+step2;
        }
        return dp[n];


    }
};
