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
    
   //RECURSIVE REVERSE A LINKED LIST
   ListNode * revLL(ListNode * head){
        if(head == NULL || head->next== NULL){
            return head;
        }
        
        // we assume that the linked list has been reversed just head is left to reverse
        // head  rest_tail   rest_head
        //  ↓      ↓         ↓
        //  1   -> 2 <- 3 <- 4
        // so we will reverse that also
        ListNode * rest_head = revLL(head->next);
        ListNode * rest_tail = head->next;
        
        rest_tail ->next = head;
        head ->next = NULL;
        return rest_head;
    }
    ListNode* reverseList(ListNode* head) {
        head = revLL(head);
        return head;
        
    }
};