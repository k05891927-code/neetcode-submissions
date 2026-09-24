class Solution {
public:

    vector<vector<int>>nei = {{-1,0},{1,0},{0,-1},{0,1}};

    bool find(int ind,int r,int c,vector<vector<char>>& board,string word){
        if(ind==word.size()){
            cout<<"yes\n";
            return true;
        }
        
        if(ind!=0 && word[ind]!=board[r][c]){
            return false;
        }
        //word[ind] is preseat at current grid element

        for(auto it:nei){
            int dr=r+it[0],dc=c+it[1];
            if(dr<0 || dc<0 || dr>=board.size() || dc>=board[0].size() || board[dr][dc]=='#' ){continue;} 
            char tmp=board[dr][dc];
            board[dr][dc]='#';
            if(find(ind+1,dr,dc,board,word)){return true;}
            board[dr][dc]=tmp;
        }
        return false;

    }

    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[0]){
                    char tmp=board[i][j];
                    board[i][j]='#';
                    if(find(0,i,j,board,word)){
                        return true;
                    }
                    board[i][j]=tmp;
                }
            }
        }
        return false;

    }
};
