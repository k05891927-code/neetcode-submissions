class Node{
    public:
    Node* arr[26]={NULL};
    int isend=0;
};

class WordDictionary {
private:
    Node* root=NULL;
public:
    WordDictionary() {
        root= new Node();
    }

    void addWord(string word) {
        Node* curr=root;
        for(int i=0;i<word.size();i++){
            if(curr->arr[word[i]-'a']==NULL)
                curr->arr[word[i]-'a']=new Node();
            curr=curr->arr[word[i]-'a'];
        }    
        curr->isend=1;
    }

    bool searchinternal(Node* curr, string word){

        if(curr->isend==1 && word.size()==0){
            return true;
        }
        else if(curr->isend==0 && word.size()==0){
            return false;
        }

        for(int i=0;i<word.size();i++){
            
            if(word[i]=='.' ){
                for(int i=0;i<26;i++){
                    if(curr->arr[i]!=NULL){
                        if(searchinternal(curr->arr[i],word.substr(1))) 
                            return true;
                    }
                }
            }
            
            else if(curr->arr[word[i]-'a']!=NULL){
                if(searchinternal(curr->arr[word[i]-'a'],word.substr(1)))
                    return true;
            }            
        }
        return false;

    }

    bool search(string word) {
        return searchinternal(root,word);
    }
};






