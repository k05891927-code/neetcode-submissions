class Solution {
public:
    //bfs
    bool connectionexist(string fr,string it){
        int cnt=0;
        for(int i=0;i<fr.size();i++){
            if(fr[i]!=it[i]){
                cnt++;
            }
        }
        return cnt==1;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(wordList.end()==find(wordList.begin(),wordList.end(),endWord))
            return 0;

        unordered_set<string>vis;
        queue<string>q;
        q.push(beginWord);
        int queue_size=1,level=1;

        while(!q.empty()){
            string fr= q.front();
            q.pop();
            vis.insert(fr);


            for(auto it: wordList){
                if(vis.count(it)==0 && connectionexist(fr,it)){
                    q.push(it);
                    vis.insert(it);
                    if(it==endWord){
                        return level+1;
                    }
                }
            }

            queue_size--;
            if(queue_size==0){
                queue_size=q.size();
                level++;    
            }
        }
        return 0;
            
    }
};