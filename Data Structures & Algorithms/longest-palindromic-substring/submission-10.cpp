class Solution {
public:
    bool ispalindrome(string &st,int i,int j,vector<vector<int>>&dp){
        if(i>=j){
            return true;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        if(st[i]!=st[j]){
            return dp[i][j]= false;
        }

        return dp[i][j]= ispalindrome(st,i+1,j-1,dp);
    }

    string longestPalindrome(string s) {
        int st=0,end=0;
        int maxlen=0;
        vector<vector<int>>dp(s.size(),vector<int>(s.size(),-1));

        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                if(ispalindrome(s,i,j,dp)){
                    if(j-i+1>maxlen){
                        st=i;end=j;
                        maxlen=j-i+1;
                    }
                }
            }
        }
        return s.substr(st,maxlen);

    }
};
