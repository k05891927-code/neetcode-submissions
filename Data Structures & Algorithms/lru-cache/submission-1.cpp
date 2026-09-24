class Node{
    public:
    int key;int val;
    Node* next;
    Node* prev;
    Node(int key){
        this->key=key;
        next=NULL;
        prev=NULL; 
    }
    Node(int key,int val){
        this->key=key;
        this->val=val;
        next=NULL;
        prev=NULL; 
    }
};

class LRUCache {
public:
    int size=0;
    int capacity=0;
    map<int,Node*>m;
    Node* head= new Node(-1);
    Node* tail= new Node(-1);

    LRUCache(int capacity) {
        this->capacity=capacity;

        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        if(m.find(key)!=m.end()){

            //remove taht node from list and add before-tail
            Node* thatnode=m[key];
            //remove from doubly LL
            thatnode->prev->next=thatnode->next;
            thatnode->next->prev=thatnode->prev;
            thatnode->prev=NULL;
            thatnode->next=NULL;

            //insert at tail-before
            thatnode->next=tail;
            thatnode->prev=tail->prev;
            tail->prev->next=thatnode;
            tail->prev=thatnode;

            return m[key]->val;
        }
        else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        //insert at tail-before
        //if overflow remove head-next, inset at tail-before

        if(size==capacity && m.find(key)==m.end()){
            //remove head->next
            Node* tmp= head->next;
            m.erase(tmp->key);
            head->next=tmp->next;
            tmp->next->prev=head;
            delete tmp;
            size--;
            
        }
        //insert at tail or just update value
        Node* thatnode=NULL;
        if(m.find(key)==m.end()){
            thatnode= new Node(key,value);
            m[key]=thatnode;
            size++;//increase size new added extra
        }
        else{
            thatnode=m[key];
            thatnode->val=value;
            //remove from doubly LL
            thatnode->prev->next=thatnode->next;
            thatnode->next->prev=thatnode->prev;
            thatnode->prev=NULL;
            thatnode->next=NULL;
            //no incerase in size
        }

        //insert thatnode at before tail
        thatnode->next=tail;
        thatnode->prev=tail->prev;
        tail->prev->next=thatnode;
        tail->prev=thatnode;

    }
};
