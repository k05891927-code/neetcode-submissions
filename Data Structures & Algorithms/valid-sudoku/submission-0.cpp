class Solution {
public:

    int isunique(vector<char>v){
        set<char>s(v.begin(),v.end());
        return v.size()==s.size();
    }

    vector<char> getrow(vector<vector<char>>& board, int r){
        vector<char>v;
        for(int i=0;i<9;i++){
            if(board[r][i]!='.')
            v.push_back(board[r][i]);
        }
        return v;
    }
    vector<char> getcol(vector<vector<char>>& board, int c){
        vector<char>v;
        for(int i=0;i<9;i++){
            if(board[i][c]!='.')
            v.push_back(board[i][c]);
        }
        return v;
        
    }
    vector<char> getsubbox(vector<vector<char>>& board, int r,int c){
        vector<char>v;
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                if(board[r+i][c+j]!='.')
                v.push_back(board[r+i][c+j]);
            }
        }
        return v;
    }


    bool isValidSudoku(vector<vector<char>>& board) {
        
        vector<vector<int>>centre= {{1,1},{1,4},{1,7},{4,1},{4,4},{4,7},{7,1},{7,4},{7,7} };

        for(auto it:centre){
            if( isunique(getsubbox(board,it[0],it[1])  )==0  ){
                return false;
            }
        }

        for(int i=0;i<9;i++){
            if( isunique(getrow(board,i)  )==0  ){
                return false;
            }
            if( isunique(getcol(board,i)  )==0  ){
                return false;
            }
        }
        return true;
    }
};
