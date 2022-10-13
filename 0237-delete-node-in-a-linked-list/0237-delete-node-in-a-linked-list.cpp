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
    void deleteNode(ListNode* node) {
        // we copy next node in temp
        ListNode * temp = node ->next;
        // then make curr nodde as temp and delete temp
        
        *node = *temp;
        delete temp;
        
    }
};