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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode * prev  = new ListNode(0);
        ListNode * newhead = prev;
        ListNode * curr = head;
        ListNode * next = head->next;
        bool flag = false;
        while(next!=NULL){
            if(curr->val != next->val){
                if(flag == false){
                    prev ->next = curr;
                    prev = curr;
                    curr = next;
                    next = next->next;
                    
                }
                else{
                    prev ->next = next;
                    curr = next;
                    next = next->next;
                }
               
                flag = false;
            }
            else{
                flag = true;
                next = next->next;
                
            }
        }
        if(flag){
            prev->next = next;
        }
        return newhead->next;
        
    }
};