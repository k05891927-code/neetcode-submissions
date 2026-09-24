class Node{
    public:
    Node* arr[26]={NULL};
    int isend=false;
};

class PrefixTree {
private:
    Node* root=NULL;

public:

    PrefixTree() {
        root = new Node();
    }

    void insert(string word) {
        Node * curr= root;
        for(int i=0;i<word.size();i++){
            if(curr->arr[word[i]-'a']==NULL){
                curr->arr[word[i]-'a']= new Node();
            }
            curr= curr->arr[word[i]-'a'];
        }
        curr->isend=1;
    }
    
    bool search(string word) {
        Node * curr= root;
        for(int i=0;i<word.size();i++){
            if(curr->arr[word[i]-'a']!=NULL){
                curr= curr->arr[word[i]-'a'];
            }
            else{
                return false;
            }
        }
        return curr->isend;
    }
    
    bool startsWith(string prefix) {
        Node * curr= root;
        for(int i=0;i<prefix.size();i++){
            if(curr->arr[prefix[i]-'a']!=NULL){
                curr= curr->arr[prefix[i]-'a'];
            }
            else{
                return false;
            }
        }
        return true;
    }
};
