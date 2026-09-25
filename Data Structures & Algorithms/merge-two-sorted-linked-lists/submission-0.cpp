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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==nullptr && list2==nullptr) return NULL;
        ListNode *x=new ListNode(0);
        ListNode *c=x;
        while(list1!=nullptr || list2!=nullptr){
            if(list1!=nullptr && (list2==nullptr || list1->val < list2->val)){
                c->val=list1->val;
                list1=list1->next;
            }
            else{
                c->val=list2->val;
                list2=list2->next;
            }
            if(list1==nullptr && list2==nullptr) break;
            c->next=new ListNode(0);
            c=c->next;
        }
        return x;
    }
};