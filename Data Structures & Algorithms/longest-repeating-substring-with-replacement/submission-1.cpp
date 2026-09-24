class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();

        int end=0;
        int start=0;
        vector<int>v(26,0);  //count
        int maxfreq=0;int maxlen=0;
        while(end<n){
            char ch= s[end];
            v[ch-'A']++;
            maxfreq= max(maxfreq,v[ch-'A']);

            while((end-start+1) -maxfreq >k){ //remove 
                v[s[start]-'A']--;
                maxfreq=0;
                for(auto it:v){
                    maxfreq=max(maxfreq,it);
                }
                start++;
            }
            if((end-start+1) -maxfreq <=k){
                maxlen=max(maxlen, end-start+1);
            }
            end++;
        }

        return maxlen;

    }
};
