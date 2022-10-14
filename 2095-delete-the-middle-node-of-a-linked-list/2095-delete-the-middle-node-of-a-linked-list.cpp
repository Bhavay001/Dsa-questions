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
    ListNode* deleteMiddle(ListNode* head) {
        if(head == NULL || head->next==NULL){
            return NULL;
        }
        ListNode* slow = head;
        ListNode * fast = head;
        
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast ->next->next;
        }
        //now slow will be pointing to the node to be deleted in both the odd and even length case
        
        ListNode * curr = head;
        //we move curr a node before slow as slow has to be deleted
        
        while(curr->next != slow){
            curr = curr->next;
        }
        // removing link from slow by pointing curr->next to next of slow
        curr->next = slow->next;
        return head;
    }
};