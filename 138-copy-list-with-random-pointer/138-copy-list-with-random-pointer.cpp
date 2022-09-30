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
        
        if(head == NULL){
            return NULL;
        }
 
        unordered_map<Node*,Node*> mp;
        Node * curr = head;
        
        // we create all the new nodes and do mapping of every node with a new node
        while(curr!=NULL){
            // ek nya node bna with val of curr
            Node * CloneNode = new Node(curr->val);
            // ab CloneNode aur curr waale ko map kardengai
            mp[curr] = CloneNode;
            curr = curr->next;
        }
        curr = head;
        // cloonin gnext and random pointer now
        while(curr!=NULL){
            // node point kar rha hai cloned linked list ka curr kai duplicate nodes par
            Node * node = mp[curr];
            // ab nedxt pointer copy karne kai liye
            node->next = mp[curr->next];
            // random pointr copy karne kai liye 
            node ->random = mp[curr->random];
            curr = curr->next;
        }
        Node * newhead = mp[head];
        return newhead;
        
        
    }
};