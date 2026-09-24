class Solution {
public:


    int LCS(int ind1,int ind2,string s1,string s2, vector<vector<int>>&dp){
        if(ind1==s1.size() || ind2==s2.size()){
            return 0;
        }
        if(dp[ind1][ind2]!=-1){return dp[ind1][ind2];}
        if(s1[ind1]==s2[ind2]){//take
            return 1+LCS(ind1+1,ind2+1,s1,s2,dp);
        }
        //not common
        return dp[ind1][ind2]= max( LCS(ind1+1,ind2,s1,s2,dp) , LCS(ind1,ind2+1,s1,s2,dp));

    }

    string longestPalindrome(string s1) {
        //lcs of s,rev(s))
        string s2(s1.rbegin(),s1.rend());
        vector<vector<int>>dp(s1.size(),  vector<int>(s2.size(),-1));
        int lenLCS= LCS(0,0,s1,s2,dp);  
        cout<<lenLCS<<endl; 

        int ind1=0,ind2=0;
        string ans="";
        while((ind1<=(s1.size()-1)) && (ind2<=(s2.size()-1))  ){

            if(s1[ind1]!=s2[ind2]){
                if(ind1+1<s1.size() && dp[ind1+1][ind2]>=dp[ind1][ind2]){
                    ind1++;
                }
                else{
                    ind2++;
                }
            }
            else{
                ans+=s1[ind1];
                ind1++;
                ind2++;
            }
        }
        return ans;

    }
};
