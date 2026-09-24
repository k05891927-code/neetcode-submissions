class Solution {
public:
    vector<vector<int>>nei={{0,1},{0,-1},{1,0},{-1,0}};
    bool isbelongs(int r,int c,vector<vector<char>>& board,string word,vector<vector<int>>& vis){
        if(word.size()==0){
            return true;
        }
        if(board[r][c]!=word[0]){
            return false; //word not matching with grid element
        }

        if(word.size()==1){
            return true;
        }

        vis[r][c]=1;
        //check neightbput for next word
        //if got true return true
        for(auto ne : nei){
            int cr=r+ne[0],cc=c+ne[1];
            if(cr>=0 && cc>=0 && cr<board.size() && cc<board[0].size() && vis[cr][cc]==0 ){
                if(isbelongs(cr,cc,board,word.substr(1),vis)){
                    vis[r][c]=0;
                    return true;
                }
                //else check through other neighbour path
            }
        }
        //else return false
        //mark it as unvisited, remove dfs trace

        vis[r][c]=0;
        return false;
    }


    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ans;
        map<int,vector<pair<int,int>>>m;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                m[board[i][j]-'a'].push_back({i,j});
            }
        }

        vector<vector<int>> vis(board.size(),vector<int>(board[0].size(),0));
        for(auto word:words){
            
            for(auto it:m[word[0]-'a']){ //start from all possible startings
                int r=it.first,c=it.second;
                if(isbelongs(r,c,board,word,vis)){
                    ans.push_back(word);
                    break;
                }
            }
        }

        return ans;

    }
};
