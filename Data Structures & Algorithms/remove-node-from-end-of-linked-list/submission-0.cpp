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

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next==NULL){
            return NULL;
        }
        ListNode* curr=head;
        
        ListNode*slow=head,*fast=head;

        while(n--){
            fast=fast->next;
        }
        ListNode*prevslow=head;

        if(fast==NULL){
            ListNode*tmp=head;
            head=head->next;
            delete tmp;
            return head;
        }

        while(fast){
            fast=fast->next;
            prevslow=slow;
            slow=slow->next;
        }
        prevslow->next=slow->next;
        delete slow;
        return head;


    }
};
