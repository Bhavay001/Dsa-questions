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
        Node * curr = head;
        Node * currnext;
        // step 1-join newnodes in bwtween of the given linked list
        while(curr!=NULL){
            Node * clonenode = new Node(curr->val);
            currnext = curr->next;
            curr->next = clonenode;
            clonenode->next = currnext;
            curr = currnext;
        }
        //step  2- assign random pointers of cloned list
        curr = head;
        while(curr!=NULL){
            if(curr->random!=NULL){
                curr->next->random = curr->random->next;
            }
           
            curr = curr->next->next;
        }
        // step 3- remove next pointers from origional -> clone and clone -> origional
        Node * origionallist = head;
        Node * clonedlist = head->next;
        Node * finalhead = head->next;
        while(origionallist!=NULL && clonedlist!=NULL){
            origionallist->next = clonedlist->next;
            origionallist = origionallist->next;
            if(origionallist!=NULL){
                clonedlist->next = origionallist->next;
            }
            clonedlist = clonedlist->next;
        }
        return finalhead;
        
    }
};