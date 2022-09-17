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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL){
            return NULL;
        }
        if(head->next==NULL){
            return head;
        }
        ListNode * prev = NULL;
        ListNode * curr = head;
        ListNode * next = head->next;
        while(next !=NULL){
            curr->next = prev;
            prev = curr;
            curr = next;
            next = curr->next; 
        }
        curr->next = prev;
        return curr;
    }
    
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return true;
        }
        ListNode * slow = head;
        ListNode * fast = head;
        // because in even length linked list we need to find the left middle taaki baad mai next waale se connect karne                mai assani ho means if 6 is the length middle mai 3rd
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        // connecting right half of the linked list to the slows next hence connecting the full linked list
        slow ->next = reverseList(slow->next);
        
        // ab slow ko uske next par point kardengai aur start mai ek aur pointer rakh dengai agar donoo ki value equal hui           to aage badha jayengai aur jabtak slow null kai equal ni aa jaata we move foward
        
        slow = slow ->next;
        ListNode *curr = head;
        
        while(slow !=NULL){
            if(slow->val != curr ->val){
                return false;
            }
            slow = slow->next;
            curr = curr ->next;
        }
        return true;
    }
};