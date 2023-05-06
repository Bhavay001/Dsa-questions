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
    
    ListNode* solve(ListNode* l1, ListNode* l2) {
        
        ListNode * head = l1; 
        while(l1 !=NULL && l2 !=NULL){
            ListNode * temp = NULL;
            while(l1!=NULL && l1->val<=l2->val){
                temp = l1;
                l1 = l1->next;   
            }
            temp->next = l2;
            std::swap(l1,l2);
        }
        
        return head;
    }
        
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        if(list1 == NULL){
            return list2;
        }
        if(list2==NULL){
            return list1;
        }
        // wvwerytime list 1 has to be aqt the smaller element
        if(list1 ->val >list2->val){
            return solve(list2,list1);
        }
        else{
            return solve(list1,list2);
        }
    }
    
};