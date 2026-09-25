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
    void reorderList(ListNode* head) {
        ListNode *fast=head;
        ListNode *slow=head;
        while(fast->next!=nullptr && fast->next->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode *r=slow->next;
        slow->next=NULL;
        ListNode *prev=nullptr;
        ListNode *temp;
        while(r){
            temp=r->next;
            r->next=prev;
            prev=r;
            r=temp;
        }

        ListNode *x=head;
        ListNode *t;
        while(prev){
            t=x->next;
            x->next=prev;
            prev=prev->next;
            x->next->next=t;
            x=x->next->next;
        }
    }
};
