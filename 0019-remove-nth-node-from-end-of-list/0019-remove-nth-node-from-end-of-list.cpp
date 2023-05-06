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
        if(head->next == NULL && n ==1){
            return NULL;
        }
        int size = 0;
        ListNode * curr = head;
        while(curr!=NULL){
            size++;
            curr = curr->next;
        }
        if(size == n){
            return head->next;
        }
        int remove = size - n-1;
        curr = head;
        while(remove>0){
            remove--;
            curr = curr->next;
        }
        if(curr->next->next == NULL){
            curr->next = NULL;
        }
        else{
            curr->next = curr->next->next;
        }
        return head;
    }
};