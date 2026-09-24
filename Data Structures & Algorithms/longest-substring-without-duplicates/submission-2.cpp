class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        if(n==0){return 0;}

        map<char,int>m;
        for(int i=0;i<256;i++){
            char ch= i;
            m[ch]=-1;
        }
        int ans=0;
        int start=0;
        for(int it=0;it<n;it++){//start , it
            char ch=s[it];
            if(m[ch]==-1){
                ans= max(ans,it-start+1);
                m[ch]=it;

            }
            else if(m[ch]!=-1){//repeated character
                start=m[ch]+1; //start from enxt position
                ans= max(ans,it-start+1);
                m[ch]=it;
            }
        }
        return ans;
    }
};
