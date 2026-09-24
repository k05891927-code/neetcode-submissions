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

    ListNode* reverse(ListNode* head){

        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode*prev=NULL;
        ListNode*curr=head;
        ListNode*ans=head;

        while(curr){
            ans=curr;

            ListNode* tmp= curr->next;
            curr->next=prev;
            prev=curr;

            curr=tmp;

        }
        return ans;

    } 


    void reorderList(ListNode* head) {
        // stack<ListNode*>st;

        ListNode* curr=head;
        ListNode* fast=head->next,*slow=head;
        while(fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }

        ListNode* middle=slow->next;
        slow->next=NULL;
        ListNode* reversed= reverse(middle);

        ListNode*dummy = new ListNode(0), *ans=dummy;

        while(curr){
            dummy->next=curr;
            dummy=dummy->next;
            curr=curr->next;

            if(reversed){
                dummy->next= reversed;
                dummy=dummy->next;
                reversed=reversed->next;
            }

        }

        head=ans->next;


    }
};
// n/2+1 , n/2
