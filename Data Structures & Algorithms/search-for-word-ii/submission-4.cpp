// class Solution {
// public:
//     vector<vector<int>>nei={{0,1},{0,-1},{1,0},{-1,0}};
//     bool isbelongs(int r,int c,vector<vector<char>>& board,string word,vector<vector<int>>& vis){
//         if(word.size()==0){
//             return true;
//         }
//         if(board[r][c]!=word[0]){
//             return false; //word not matching with grid element
//         }

//         if(word.size()==1){
//             return true;
//         }

//         vis[r][c]=1;
//         //check neightbput for next word
//         //if got true return true
//         for(auto ne : nei){
//             int cr=r+ne[0],cc=c+ne[1];
//             if(cr>=0 && cc>=0 && cr<board.size() && cc<board[0].size() && vis[cr][cc]==0 ){
//                 if(isbelongs(cr,cc,board,word.substr(1),vis)){
//                     vis[r][c]=0;
//                     return true;
//                 }
//                 //else check through other neighbour path
//             }
//         }
//         //else return false
//         //mark it as unvisited, remove dfs trace

//         vis[r][c]=0;
//         return false;
//     }


//     vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
//         vector<string> ans;
//         map<int,vector<pair<int,int>>>m;
//         for(int i=0;i<board.size();i++){
//             for(int j=0;j<board[0].size();j++){
//                 m[board[i][j]-'a'].push_back({i,j});
//             }
//         }

//         vector<vector<int>> vis(board.size(),vector<int>(board[0].size(),0));
//         for(auto word:words){
            
//             for(auto it:m[word[0]-'a']){ //start from all possible startings
//                 int r=it.first,c=it.second;
//                 if(isbelongs(r,c,board,word,vis)){
//                     ans.push_back(word);
//                     break;
//                 }
//             }
//         }

//         return ans;

//     }
// };


class Node{
public:
    Node* arr[26]={NULL};
    int isend=0;
    string wor=""; // save full word at end
};

class Trie{
    
    public:
    Node* root=NULL;

    Trie(){
        root = new Node();
    }

    void addword(string word){
        Node* curr= root;
        for(int i=0;i<word.size();i++){
            if(curr->arr[word[i]-'a']==NULL){
                curr->arr[word[i]-'a']= new Node();
            }
            curr=curr->arr[word[i]-'a'];
        }
        curr->wor= word;// save full word at end
        curr->isend=1;

    }
    bool isword(string word){
        Node* curr= root;
        for(int i=0;i<word.size();i++){
            if(curr->arr[word[i]-'a']!=NULL){
                curr=curr->arr[word[i]-'a'];
            }
            else{
                return 0;
            }
            
        }
        return curr->isend;
    }
};

class Solution {
public:
    vector<string>ans;
    vector<vector<int>>nei= {{0,1},{0,-1},{1,0},{-1,0}};
    void givewordsstartingwith(int i,int j,vector<vector<char>>& board, Node * tr){
        if( tr==NULL){  //nothing to search for
            return;
        }
        // Move to Trie node corresponding to current board character
        tr = tr->arr[board[i][j]-'a'];
        if( tr==NULL){  //nothing to search for
            return;
        }
        //keep checking if trie node isend true for any place

        if(tr->isend==1){
            tr->isend=0; // no duplication
            ans.push_back(tr->wor);
        }

        char currenchar=board[i][j];
        board[i][j]='#';
        //discover neighbours
        for(auto ne: nei ){
            int r=i+ne[0],c=j+ne[1];
            if(r>=0 && c>=0 && r<board.size() && c<board[0].size() && board[r][c]!='#'){
                char neichar= board[r][c];
                if(tr->arr[board[r][c]-'a'] != NULL)
                    givewordsstartingwith(r,c,board,tr);  
            }

        }
        board[i][j]=currenchar;

        


    }


    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie *tr=new Trie(); 
  
        for(auto word : words){
            tr->addword(word);
        }

        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                givewordsstartingwith(i,j,board,tr->root);
            }
        }

        return ans;

    }
};