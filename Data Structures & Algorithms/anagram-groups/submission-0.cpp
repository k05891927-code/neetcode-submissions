class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string> >m;
        for(auto it:strs){
            string cpy= it;
            sort(cpy.begin(),cpy.end());
            m[cpy].push_back(it);
        }

        vector<vector<string>>ans;
        for(auto it:m){
            vector<string> subans;
            for(auto word:it.second)
                subans.push_back(word);
            
            ans.push_back(subans);
        }

        return ans;

    }
};
