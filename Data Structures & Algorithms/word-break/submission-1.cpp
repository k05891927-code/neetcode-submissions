class Solution {
public:

    bool solve(int ind,string &s,vector<string>& wordDict,vector<int>&dp){
        if(ind==s.size()){return true;}
        if(dp[ind]!=-1){return dp[ind];}
        bool flag=false;
        for(int j=ind;j<s.size();j++){
            if( find(wordDict.begin(),wordDict.end(), s.substr(ind, j-ind+1) ) !=wordDict.end() ){
                flag = flag || solve(j+1,s,wordDict,dp);
            }
        }
        return dp[ind]=flag;

    }

    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int>dp(s.size(),-1);
        bool ans= solve(0,s,wordDict,dp);
        return ans;

    }
};
