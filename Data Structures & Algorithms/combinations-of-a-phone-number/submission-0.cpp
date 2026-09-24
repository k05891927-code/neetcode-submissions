class Solution {
public:
    map<char,string>m;


    void solve(int ind,string &curr,vector<string>&ans,string digits){
        if(ind==digits.size()){
            if(curr.size()!=0)
                ans.push_back(curr);
            return;
        }
        char currdigit=digits[ind];

        for(char alpha:m[currdigit]){
            curr.push_back(alpha);
            solve(ind+1, curr,ans,digits);
            curr.pop_back();
        }


    }

    vector<string> letterCombinations(string digits) {
        int ind=0;
        vector<string>ans;
        string curr="";

        m['2']="abc";
        m['3']="def";
        m['4']="ghi";
        m['5']="jkl";
        m['6']="mno";
        m['7']="pqrs"; 
        m['8']="tuv";
        m['9']="wxyz";
    

        solve(ind,curr,ans,digits);
        return ans;

    }
};
