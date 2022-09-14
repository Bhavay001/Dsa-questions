/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
         if(head ==NULL || head->next ==NULL ){
            return NULL;
        }
        // this is the extension of slow and fast pointer(tortoise) algorithm 
        // 1) in this we firstfind the point where slow and fast pointers meet is they are meenting and break
        // 2) then we make a curr pointer pointing to head and then move either of slow/fast pointer and curr pointer qa                step forward till the meet 
        // 3) we return the meeting point
        
        ListNode * slow = head;
        ListNode * fast = head;
        ListNode * curr = head;
        
        while(fast!=NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            // break when slow pointer is at same point with fast pointer
            if(slow == fast){
                // now find the point of interserction when curr and fast meet
                while(curr != fast){
                    curr = curr ->next;
                    fast = fast->next;
                }
                return curr;
            }
        }
        return NULL;
    }
};


 