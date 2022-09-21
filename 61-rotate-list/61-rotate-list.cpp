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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || k == 0 || head->next ==NULL){
            return head;
        }
        int count = 0;
        ListNode * curr = head;
        while(curr!=NULL){
            count++;
            curr = curr->next;
        }
        while(k>count){
            k -=count;
        }
        if(k==count){
            return head;
        }
        curr = head;
        ListNode * prev;
        int i =0;
        while(i<count-k){
            prev = curr;
            curr = curr->next;
            i++;
        }
        ListNode *temp = curr;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        prev->next = NULL;
        temp->next = head;
        return curr;
    }
};