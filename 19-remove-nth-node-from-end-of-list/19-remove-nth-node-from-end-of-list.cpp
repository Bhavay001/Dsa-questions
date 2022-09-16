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
        if(head == NULL || head->next == NULL){
            return NULL;
        }
        
        ListNode * curr = head;
        int count =0;
        while(curr!=NULL){
            curr = curr->next;
            count ++;
        }
        int d = count - n;
        if(d==0){
            return head->next;
        }
        int count1 = 1;
        curr = head;
        while(count1<d){
            curr = curr->next;
            count1++;
        }
        curr ->next = curr->next->next;
        return head;
    
    }
};