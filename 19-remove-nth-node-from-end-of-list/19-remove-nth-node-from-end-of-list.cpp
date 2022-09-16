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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * fast = head;
        ListNode * slow = head;
        
        // fisst we move fast pointer n-1 time forward in the ll
        for(int i =0;i<n;i++){
            fast = fast ->next;
        }
        // ye jab hoga jab size aur n equal hongai to 1st node remove karna hoga to head ka next return kardengai
        if(fast ==NULL){
            return head->next;
        }
        // now we move out fast pointer and slow pointer forward till fast ->next is not nnull matlab 1 iteration kam
        while(fast->next !=NULL){
            slow = slow ->next;
            fast = fast ->next;
        }
        
        // ab slow jo point karrha hoga wo 1 position kam hoga to 1 position kai aage waale kai aage se pointer hta dengai
        slow->next = slow ->next->next;
        return head;
    }
};