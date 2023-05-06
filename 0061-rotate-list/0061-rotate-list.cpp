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
        if(head == NULL || k == 0 || head->next ==NULL){
            return head;
        }
        if(k==0){
            return head;
        }
        int size = 0;
        ListNode * curr = head;
        while(curr != NULL){
            curr = curr->next;
            size++;
        }
        

        while(k>size){
            k -=size;
        }
        if(k==size){
            return head;
        }
        curr = head;
        int pos = size - k-1;
        while(pos>0){
            curr = curr->next;
            pos--;
        }
        ListNode *temp = curr->next;
        curr->next = NULL;
        curr = temp;
        while(curr->next!=NULL){
            curr = curr->next;
        }
        curr->next = head;
        return temp;
    }
};