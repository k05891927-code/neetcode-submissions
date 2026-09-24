/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class comp{
    public:
    bool operator()(ListNode*a,ListNode*b){
        return a->val > b->val;
    }
};


class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode* , vector<ListNode*>,comp>pq;//minheap by val

        ListNode*dummy= new ListNode(-1),*ans=dummy;

        for(auto it:lists){
            if(it!=NULL){
                pq.push(it);
            }
        }

        while(!pq.empty()){
            ans->next= pq.top();
            if(pq.top()->next){
                pq.push(pq.top()->next);
            }
            pq.pop();
            ans=ans->next;
        }
        return dummy->next;
        
    }
    
};
