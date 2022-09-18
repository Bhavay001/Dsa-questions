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
    ListNode* solve(ListNode* list1, ListNode* list2){
        
        // 1 case can be 1st ka next null ho wo alag se handle kar lengai
        if(list1->next ==NULL){
            list1->next = list2;
            return list1;
        }
        // we just take two ponters from list 1 curr and next and check if list 2 curr can lie b/w it if not we move our            window
        ListNode * curr1 = list1;
        ListNode * next1 = list1->next;
        ListNode * curr2 = list2;
        ListNode * next2 = list2->next;
        // kyonki next1 aur curr1 kai beech mai daal rhe hain to wo null ni hone chahie aur curr2 to daalna hi hai wo bhi       null ni hona chahie
        while(next1!=NULL && curr2!=NULL){
            // if curr2 lies in between
            if(curr1->val<= curr2-> val && curr2->val<= next1->val){
                // inserting the node
                next2 = curr2->next; // to avoid losing of nodes
                curr1->next = curr2;
                curr2->next = next1;
                
                // updating all the pointers
                curr1 = curr2;
                curr2 = next2;
            }
            else{
                // if curr2 does not lies in between we move forward curr1 and next1
                curr1 = next1; 
                next1 = next1->next;
                
                // next1 null na ho gya ho
                if(next1==NULL){
                    // curr1 kai next se aage ki puri linked list connext kardo
                    curr1->next = curr2;
                    return list1;
                }
            }
        }
        return list1;
        
    }
    
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL){
            return list2;
        }
        if(list2==NULL){
            return list1;
        }
        // now in this we assign list1 to the the list having data smaller than the other 
        if(list1->val<=list2->val){
            return solve(list1,list2);
        }
       else if(list2->val<list1->val){
           return solve(list2,list1);
       }
        // will never reach here just to return something
        return list1;
    }
};