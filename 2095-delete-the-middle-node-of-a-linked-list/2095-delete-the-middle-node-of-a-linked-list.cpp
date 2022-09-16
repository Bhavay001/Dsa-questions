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
        int count = 1;
        while(fast!=NULL && fast->next !=NULL){
            slow = slow->next;
            count++;
            fast = fast ->next->next;
        }
       ListNode * curr = head;
        int count1 = 1;
        while(count1<count-1){
            curr = curr->next;
            count1++;
        }
        curr->next = curr->next->next;
       
        return head;
    }
};