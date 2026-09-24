class Solution {
public:

    bool giveedge(string st1,string st2,char& ch1,char& ch2){
        for(int i=0;i<min(st1.size(),st2.size());i++ ){
            if(st1[i]!=st2[i]){
                ch1=st1[i];
                ch2=st2[i];
                return true;
            }
        }
        return false;
    }
    string foreignDictionary(vector<string>& words) {
        map<char,vector<char>>adj;

        for(int i=1;i<words.size();i++){
            
            char ch1='#',ch2='#';
            if(giveedge(words[i-1],words[i],ch1,ch2))
                adj[ch1].push_back(ch2);
        }
        vector<int>ind(26,0);
        for(auto k:adj){
            for(auto cha:k.second){
                ind[cha-'a']++;
            }
        }
        queue<char>q;
        for(int i=0;i<26;i++){
            char ch=i+'a';
            if(ind[i]==0 && adj.find(ch)!=adj.end()){
                q.push(ch);
            }
        }
        string ans="";
        while(!q.empty()){
            char ch= q.front();
            q.pop();
            ans+=ch;

            for(auto it:adj[ch]){
                ind[it-'a']--;
                if(ind[it-'a']==0){
                    q.push(it);
                }
            }

        }

        for(auto it:ind){
            if(it>0){
                return "";
            }
        }

        return ans;



    }
};
