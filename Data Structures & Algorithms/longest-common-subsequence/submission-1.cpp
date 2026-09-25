class Solution {
public:

    int LCS(int ind1,int ind2, string st1,string st2,vector<vector<int>>&dp){
        if(ind1==st1.size() || ind2==st2.size()){return 0;}

        if(dp[ind1][ind2]!=-1){return dp[ind1][ind2];}
        if(st1[ind1]==st2[ind2]){
            return dp[ind1][ind2]= 1+ LCS(ind1+1,ind2+1,st1,st2,dp);
        }
        return dp[ind1][ind2]= max( LCS(ind1+1,ind2,st1,st2,dp) , LCS(ind1,ind2+1,st1,st2,dp)  );

    }

    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>>dp(text1.size(),vector<int>(text2.size(),-1));
        int ans=LCS(0,0,text1,text2,dp);
        return ans;
    }
};
