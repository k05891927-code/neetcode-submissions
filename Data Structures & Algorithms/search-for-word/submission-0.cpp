class Solution {
public:

    vector<vector<int>>nei = {{-1,0},{1,0},{0,-1},{0,1}};

    bool find(int ind,int r,int c,vector<vector<char>>& board,string word){
        if(ind==word.size()){
            cout<<"yes\n";
            return true;
        }
        
        if( word[ind]!=board[r][c]){
            return false;
        }
        //word[ind] is preseat at current grid element
        bool flag=false;
        for(auto it:nei){
            int dr=r+it[0],dc=c+it[1];
            if(dr<0 || dc<0 || dr>=board.size() || dc>=board[0].size() || board[dr][dc]=='#' ){continue;} 
            char tmp=board[dr][dc];
            board[dr][dc]='#';
            flag = flag || find(ind+1,dr,dc,board,word);
            board[dr][dc]=tmp;
        }
        return flag;

    }

    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[0]){
                    if(find(0,i,j,board,word)){
                        return true;
                    }
                }
            }
        }
        return false;

    }
};
