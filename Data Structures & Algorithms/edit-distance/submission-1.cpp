class Solution {
public:

    int solve(int ind1,int ind2,string word1,string word2,vector<vector<int>>&dp){
        if(ind1==word1.size() && ind2==word2.size()){
            return 0;
        }
        else if(ind2==word2.size()){
            return word1.size()-ind1;
        }
        else if(ind1==word1.size()){
            return word2.size()-ind2;
        }
        if(dp[ind1][ind2]!=-1){return dp[ind1][ind2];}
        if(word1[ind1]==word2[ind2]){
            return dp[ind1][ind2]=0+solve(ind1+1,ind2+1,word1,word2,dp);
        }
        else{
            //insert
            int ins=1+solve(ind1,ind2+1,word1,word2,dp);
            //delete
            int del=1+solve(ind1+1,ind2,word1,word2,dp);
            //replace
            int rep=1+solve(ind1+1,ind2+1,word1,word2,dp);

            return dp[ind1][ind2]= min({ins,del,rep});
        }


    }

    int minDistance(string word1, string word2) {
        int ans;
        vector<vector<int>>dp(word1.size(),vector<int>(word2.size(),-1));
        ans=solve(0,0,word1,word2,dp);
        return ans;
    }
};
