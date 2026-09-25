/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==nullptr) return NULL;
        Node *c=head;
        while(c!=nullptr){
            Node *n=new Node(c->val);
            n->next=c->next;
            c->next=n;
            c=n->next;
        }
        c=head;
        while(c!=nullptr){
            if(c->random!=nullptr){
                c->next->random=c->random->next;
            }
            c=c->next->next;
        }
        c=head;
        Node *temp=head->next;
        while(c!=nullptr){
            Node *x=c->next;
            c->next=x->next;
            if(x->next!=nullptr) x->next=x->next->next;
            c=c->next;
        }
        return temp;
    }
};