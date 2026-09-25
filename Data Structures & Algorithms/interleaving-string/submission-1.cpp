class Solution {
public:

    bool issame(int i1, int i2, string& s1,string &s2){
        if(s1.size()-i1 != s2.size()-i2){return false;}
        while(i1<s1.size()){
            if(s1[i1]!=s2[i2]){return false;}
            i1++;i2++;
        }
        return true;
    }

    int solve(int ind1,int ind2,int ind3, string &s1, string &s2, string& s3,vector<vector<vector<int>>>&dp){

        if(ind1==s1.size()){//s1 exhausted , check s2 remaining
            return issame(ind2,ind3,s2,s3);
        }
        if(ind2==s2.size()){
            return issame(ind1,ind3,s1,s3);
        }
        if(dp[ind1][ind2][ind3]!=-1){return dp[ind1][ind2][ind3];}
        if(s1[ind1]==s3[ind3] && s2[ind2]!=s3[ind3]){
            return dp[ind1][ind2][ind3]=solve(ind1+1,ind2,ind3+1,s1,s2,s3,dp);
        }
        else if(s2[ind2]==s3[ind3] && s1[ind1]!=s3[ind3]){
            return dp[ind1][ind2][ind3]=solve(ind1,ind2+1,ind3+1,s1,s2,s3,dp);
        }
        else if(s2[ind2]==s3[ind3] && s1[ind1]==s3[ind3]){
            return dp[ind1][ind2][ind3]=solve(ind1+1,ind2,ind3+1,s1,s2,s3,dp) || solve(ind1,ind2+1,ind3+1,s1,s2,s3,dp);
        }
        else{ //no char match with s3
            return false;
        }

    }


    bool isInterleave(string s1, string s2, string s3) {
        //|n - m| <= 1 is just redefining interleaving, so lite
        if(s1.size()+s2.size()!=s3.size()){return false;}
        int ans;
        vector<vector<vector<int>>>dp (  s1.size(), vector<vector<int>>( s2.size(), vector<int>(s3.size(),-1) )   );
        ans=solve(0,0,0,s1,s2,s3,dp);
        return ans;

    }
};
