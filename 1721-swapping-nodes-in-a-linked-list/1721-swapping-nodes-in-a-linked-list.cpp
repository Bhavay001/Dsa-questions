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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode * slow = head;
        int count = 1;
        while(count<k){
            slow = slow->next;
            count++;
        }
        ListNode * fast = slow;
        ListNode * slow1 =head;
        while(fast!=NULL && fast->next!=NULL){
            slow1 = slow1->next;
            fast = fast->next;
        }
        swap(slow->val,slow1->val);
        return head;
        
    }
};