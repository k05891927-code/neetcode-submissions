class Solution {
public:
    bool ispalindrome(string st,int i,int j){
        if(i>=j){
            return true;
        }

        if(st[i]!=st[j]){
            return false;
        }

        return ispalindrome(st,i+1,j-1);
    }

    string longestPalindrome(string s) {
        int st=0,end=0;
        int maxlen=0;

        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                if(ispalindrome(s,i,j)){
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
