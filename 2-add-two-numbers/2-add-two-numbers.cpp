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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 ==NULL){
            return l2;
        }
        if(l2 == NULL){
            return l1;
        }
        ListNode * curr1 = l1;
        ListNode * curr2 = l2;
        ListNode * dummy = new ListNode();
        ListNode * temp = dummy;
        int carry = 0;
        //making generic code
        
        while(curr1 !=NULL || curr2!=NULL || carry !=0){
      
            // NULL add hone waala case bach gya
            int val1 = 0;
            if(curr1 !=NULL){
                val1 = curr1->val;
            }
            int val2 = 0;
            if(curr2 !=NULL){
                val2 = curr2->val;
            }
            int sum = carry + val1 + val2;
            int digit = sum%10;
            carry = sum/10;
            ListNode * node = new ListNode(digit);
            temp ->next = node;
            temp = temp->next;
            // ab next mai bhi jabhi ho agar not null
            if(curr1!=NULL){
                curr1 = curr1->next;
            }
            if(curr2!=NULL){
                curr2 = curr2->next;
            }
            
        }

        return dummy ->next;
    }
};