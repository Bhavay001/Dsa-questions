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
    ListNode * findmid(ListNode * head){
        ListNode * slow = head;
        ListNode * fast = head;
        while(fast->next !=NULL && fast->next->next!=NULL){
            slow = slow ->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    ListNode *mergeSort(ListNode * left, ListNode * right){
        if(left==NULL){
            return right;
        }
        if(right==NULL){
            return left;
        }
        // merge 2 sorted lists
        // we make a dummy node and then attack the small tode next it
        ListNode * ans = new ListNode(-1);
        ListNode * curr = ans;
        while(left!=NULL && right!=NULL){
            if(left->val<=right->val){
                curr->next = left;
                curr = left;
                left = left->next;
            }
            else if(right->val<left->val){
                curr->next = right;
                curr = right;
                right = right->next;
            }
        }
        if(left!=NULL){
            curr->next = left;
        }
        if(right!=NULL){
            curr->next = right;
        }
    
        return ans->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        
        // now we have to perform merge sort
        // first we need to have middle element for that
        ListNode * mid = findmid(head);
        
        // now we have to divide list in two halves
        ListNode * left = head;
        ListNode * right = mid->next;
        mid->next = NULL;
        
        // now we recursive sort the left part and the right part
        left = sortList(left);
        right = sortList(right);
        
        // now we need to merge two sorted linked lists
        
        ListNode * result = mergeSort(left,right);
        return result;
        
        
    }
};