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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL){
            return NULL;
        }
        // this approach now what we do is make curr1 point headA and curr2 to headB initially
        // now we move forward both the curr1 and curr2 till they become equal
        // if curr1 becomes null we make curr1 point to haadB
        // if curr2 becomes null we make curr2 point to headA
        // in the second iteration of curr's they come at same level/ means same distance between them
        ListNode * curr1 = headA;
        ListNode * curr2 = headB;
        while(curr1 != curr2){
            if(curr1 == NULL){
                curr1 = headB;
            }
            else{
                curr1 = curr1 ->next;
            }
            if(curr2 == NULL){
                curr2 = headA;
            }
            else{
                curr2 = curr2->next;
            }
        }
        return curr1;
    }
};