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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *temp=head;
        ListNode *prev=head;
        while(temp!=nullptr){
            ListNode *kn=kth(temp,k);
            if(kn==nullptr) break;
            ListNode *next=kn->next;
            kn->next=nullptr;
            if(temp==head){
                head=rev(temp);
            }
            else{
                prev->next=rev(temp);
            }
            temp->next = next;
            prev = temp;
            temp = next;
        }
        return head;
    }
    ListNode* kth(ListNode* temp,int k){
        for(int i=1;i<k;i++){
            if(temp!=nullptr){
                temp=temp->next;
            }
            else{
                return nullptr;
            }
        }
        return temp;
    }
    ListNode* rev(ListNode* head){
        ListNode *curr=head;
        ListNode *t=nullptr;
        while(curr!=nullptr){
            ListNode *n=curr->next;
            curr->next=t;
            t=curr;
            curr=n;
        }
        return t;
    }
};
