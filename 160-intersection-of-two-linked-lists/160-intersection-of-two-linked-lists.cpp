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
        if(headA ==NULL || headB==NULL){
            return NULL;
        }
        ListNode * curr1 = headA;
        ListNode * curr2 = headB;
        int countA = 0;
        int countB = 0;
        // first we find the size of the first and second list
        while(curr1!=NULL){
            countA++;
            curr1 = curr1->next;
        }
        while(curr2!=NULL){
            countB++;
            curr2 = curr2->next;
        }
        curr1 = headA;
        curr2 = headB;
        // we find the absolute difference between the size of both the linked list
        int d = abs(countA - countB);
        // we run the loop d no of time and if size of 1st ll is greater we move its curr forward else we move the                  2nd lls curr forward
        for(int i =0;i<d;i++){
            if(countA> countB){
                curr1 =curr1->next;
            }
            else if(countA<countB){
                curr2 = curr2 ->next;
            }
            
        }
        // now we compare the nodes of first and second linked list if they are equal we break and return curr pointer
        while(curr1!=NULL && curr2 !=NULL){
            if(curr1 == curr2){
                break;
            }
            curr1 = curr1->next;
            curr2 = curr2 ->next;
        }
        return curr1;
       
    }
};