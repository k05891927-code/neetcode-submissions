class Solution {
public:
    map<string,char>m;//number, alpha
    
    bool isvalid(string &s,int ind,int last){
        if(last-ind==0){
            if(m.find(s.substr(ind,1))!=m.end()){
                return true;
            }
            else{
                return false;
            }
        }
        if(last-ind==1){
            if(m.find(s.substr(ind,2))!=m.end()){
                return true;
            }
            else{
                return false;
            }
        }
        return false;//dummy returrn
    }

    int solve(int ind,string &s,vector<int>&dp){
        if(ind==s.size()){
            return 1;
        }
        if(dp[ind]!=-1){return dp[ind];}
        int cnt=0;
        for(int delta=0;delta<=1;delta++){
            if(ind+delta<s.size()&&  isvalid(s,ind,ind+delta)){
                cnt+=solve(ind+delta+1,s,dp);
            }
        }
        return dp[ind]=cnt;


    }
    
    int numDecodings(string s) {
        for(int i=1;i<=26;i++){
            m[to_string(i)]='A'+i-1;
        }
        //made map
        vector<int>dp(s.size(),-1);
        int ans=solve(0,s,dp);

        return ans;

    }
};
