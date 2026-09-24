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
    ListNode* reverse(ListNode*head){
        ListNode*prev=NULL;
        ListNode*curr=head;

        while(curr){
            ListNode*tmp= curr->next;
            curr->next=prev;
            prev=curr;
            curr=tmp;
        }
        return prev;

    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        int cnt=0;
        ListNode* curr=head;
        ListNode*startofotherpart=NULL;
        ListNode*prevfi=NULL;
        while(curr){
            cnt++;
            prevfi=curr;
            curr=curr->next;
            if(cnt==k){
                break;
            }
            
        }
        if(cnt<k){
            return head;
        }
        // if(curr==NULL){
        //     return head;
        // }
        else{
            // curr | n1, n2, n3
            ListNode* laterpart=reverseKGroup(curr,k);
            prevfi->next=NULL;
            ListNode*goingtobetail = head;
            ListNode*firstparthead =reverse(head);
            goingtobetail->next=laterpart;
            return firstparthead;

        }

    }
};
