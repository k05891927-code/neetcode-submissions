class Solution {
public:
    bool ispalindrome(string st,int i,int j){
        // int i=0,j=st.size()-1;
        while(i<j){
            if(st[i]!=st[j]){return false;}
            i++;j--;
        }
        return true;
    }

    void solve(int ind,vector<string>curr,vector<vector<string>>&ans,string st){
        if(ind==st.size()){
            ans.push_back(curr);
            return;
        }

        for(int k=ind;k<st.size();k++){
            if(ispalindrome(st,ind,k)){
                curr.push_back(st.substr(ind,k-ind+1));
                solve(k+1,curr,ans,st);
                curr.pop_back();
            }
        }

    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>curr;
        solve(0,curr,ans,s);
        return ans;
    }
};
