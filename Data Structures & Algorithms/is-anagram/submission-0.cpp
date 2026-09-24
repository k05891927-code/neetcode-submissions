class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>vs(26,0),vt(26,0);

        for(auto it:s){
            vs[it-'a']++;
        }
        for(auto it:t){
            vt[it-'a']++;
        }

        return vs==vt;

    }
};
