class Solution {
public:

    string encode(vector<string>& strs) {
        if(strs.size() ==1 ){
            return strs[0];
        }
        string en=strs[0];
        for(int i=1;i<strs.size();i++){
            en+="$-";
            en+=strs[i];
        }
        return en;
    }

    vector<string> decode(string s) {
        vector<string> finalans;

        string curr="";
        for(int i=0;i<s.size();i++){
            char ch = s[i];
            if(ch=='$' && i+1<s.size() && s[i+1]=='-'){
                i++;
                finalans.push_back(curr);
                curr="";
                continue;
            }
            else{
                curr+=ch;
            }
        }
        finalans.push_back(curr);
        return finalans;
    }
};
