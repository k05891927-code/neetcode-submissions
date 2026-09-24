class Solution {
public:

    void giveedge(string st1,string st2,char& ch1,char& ch2){
        for(int i=0;i<min(st1.size(),st2.size());i++ ){
            if(st1[i]!=st2[i]){
                ch1=st1[i];
                ch2=st2[i];
                return;
            }
        }
    }

    string foreignDictionary(vector<string>& words) {
        map<char,vector<char>>adj;

        vector<int>ind(26,-1);
        
        for(int i=0;i<words.size();i++){

            for(int j=0;j<words.size();j++){
                if(i>=j)
                    continue;
                
                char ch1='#',ch2='#';
                giveedge(words[i],words[j],ch1,ch2);
                if(ch1=='#')
                    continue;
                adj[ch1].push_back(ch2);
                if(ind[ch1-'a']==-1){
                    ind[ch1-'a']=0;
                }
                if(ind[ch2-'a']==-1){
                    ind[ch2-'a']=0;
                }
                ind[ch2-'a']++;

                }
        }

        for(auto it:ind){cout<<it<<" ";}
        
        queue<char>q;string ans="";
        for(int i=0;i<26;i++){
            char ch=i+'a';
            if(ind[i]==0 && adj.find(ch)!=adj.end()){
                q.push(ch);
                ans+=ch;

                cout<<ans<<endl;
            }
        }
        cout<<ans<<endl;
        while(!q.empty()){
            char ch= q.front();
            q.pop();

            for(auto it:adj[ch]){
                ind[it-'a']--;
                if(ind[it-'a']==0){
                    q.push(it);
                    ans+=it;
                    cout<<ans<<endl;
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
