class Solution {
public:

    int ispalindrome(int i,int j,string& st,vector<vector<int>>&dp){
        if(i>j){
            return true;
        }
        if(dp[i][j]!=-1){return dp[i][j];}
        if(st[i]!=st[j]){
            return dp[i][j]=false;
        }
        return dp[i][j]=ispalindrome(i+1,j-1,st,dp);
    }

    int countSubstrings(string s) {
        int cnt=0;
        vector<vector<int>>dp(s.size(),vector<int>(s.size(),-1));

        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                if(ispalindrome(i,j,s,dp)){
                    cnt++;
                }
            }
        }
        return cnt;

    }
};
