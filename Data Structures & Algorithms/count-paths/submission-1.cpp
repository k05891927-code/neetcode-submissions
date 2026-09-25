class Solution {
public:

    int solve(int r,int c, int m,int n,vector<vector<int>>&dp){
        if(r==m && c==n){return 1;}
        if(r>m || c>n){return 0;}
        if(dp[r][c]!=-1){return dp[r][c];}

        return dp[r][c]=solve(r+1,c,m,n,dp)+solve(r,c+1,m,n,dp);

    }


    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        int ans=solve(0,0,m-1,n-1,dp);
        return ans;
    }
};
