class Solution {
public:

    int solve(int ind1,int ind2,string s,string t,vector<vector<int>>&dp){
        if(ind1==s.size() &&ind2==t.size()){
            return 1;
        }
        if(ind1==s.size()){
            return 0;
        }
        if(dp[ind1][ind2]!=-1){return dp[ind1][ind2];}
        int take=0;
        //take
        if(s[ind1]==t[ind2]){
            take=solve(ind1+1,ind2+1,s,t,dp);
        }
        //nottake
        int nottake=solve(ind1+1,ind2,s,t,dp);
        return dp[ind1][ind2]=take+nottake;

    }

    int numDistinct(string s, string t) {
        int ans;
        vector<vector<int>>dp(s.size()+1,vector<int>(t.size()+1,-1));
        ans=solve(0,0,s,t,dp);
        return ans;
    }
};
