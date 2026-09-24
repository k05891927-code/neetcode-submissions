class Solution {
public:
    bool isPalindrome(string s) {
        string st="";
        for(auto ch:s){
            if( ('a'<=ch && ch<='z') ||  ('0'<=ch && ch<='9') ){
                st+=ch;
            }
            else if('A'<=ch && ch<='Z'){
                char c=ch;
                c=ch-'A'+'a';
                st+=c;
            }
        }
        string rev=st;
        reverse(rev.begin(),rev.end());
        return st==rev;
    }
};
