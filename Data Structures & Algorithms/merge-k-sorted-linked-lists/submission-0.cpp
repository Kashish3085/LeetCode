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
class compare{
    public:
    bool operator()(ListNode *a,ListNode *b){
       return a->val>b->val; 
    } 
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,compare>pq;
        ListNode *d=new ListNode(-1);
        ListNode *temp=d;
        for(int i=0;i<lists.size();i++){
            if(lists[i]!=nullptr){
                pq.push(lists[i]);
            }
        }
        while(!pq.empty()){
            temp->next=pq.top();
            pq.pop();
            temp=temp->next;
            if(temp->next!=nullptr){
                pq.push(temp->next);
            }
        }
        return d->next;

    }
};
