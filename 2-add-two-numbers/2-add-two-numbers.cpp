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
        // jab dono nodes mai value ho
        while(curr1 !=NULL && curr2!=NULL){
            // add kardo
            int sum = carry + curr1->val + curr2->val;
            int digit = sum%10;
            carry = sum/10;
            ListNode * node = new ListNode(digit);
            temp ->next = node;
            temp = temp->next;
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        // jabtak curr1 null na ho jaaye add karte jao
        while(curr1!=NULL){
            int sum = curr1->val+ carry;
            int digit = sum%10;
            carry = sum/10;
            ListNode * node = new ListNode(digit);
            temp ->next = node;
            temp = temp->next;
            curr1 = curr1->next;
        }
        // jabtak curr2 null na ho jaaye add karte jao
        while(curr2!=NULL){
            int sum = curr2->val+ carry;
            int digit = sum%10;
            carry = sum/10;
            ListNode * node = new ListNode(digit);
            temp ->next = node;
            temp = temp->next;
            curr2 = curr2->next;
        }
        
        // carry bhi to null bachna chahie aakhri mai warna jitna caary hai utnai unit ki node add kardengai
        while(carry !=0){
            int sum = carry;
            int digit = sum%10;
            carry = sum/10;
            ListNode * node = new ListNode(digit);
            temp ->next = node;
            temp = temp->next;
        }
        return dummy ->next;
    }
};