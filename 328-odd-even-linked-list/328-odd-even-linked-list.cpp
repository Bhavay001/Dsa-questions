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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL){
            return NULL;
        }
        // if the linked list has 1 or 2 elements we just return thre head as our final answer
        if(head->next == NULL || head->next->next == NULL){
            return head;
        }
        
        // now the approach is to make to seperate linked list connections for odd and even and at the end connect
        // odd ->next = even_start
        // we will require 3 pointer odd and even for makin respective linked list and even_start to connct odd tail to                 head of even
        // in the odd sized ll the even will be null and in even sized ll even ->next will be NULL
        ListNode * odd = head;
        ListNode * even = head->next;
        ListNode * even_start = head->next;
        
        while(even !=NULL && even ->next !=NULL){
            odd ->next = even ->next;
            odd = odd ->next;   // i.e pointing 1st node to 3rd then moving odd to 3rd node
            even->next = odd ->next;
            even = even->next;   // i.e pointing 2st node to 4th then moving even to 4th node
        }
        // now we come out when the even is NULL or its next is NULL
        // we have to link the odd the the even_start;
        odd->next = even_start;
        return head;
    }
    
};