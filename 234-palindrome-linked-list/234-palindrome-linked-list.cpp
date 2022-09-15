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
    vector<int> ans;
    bool isPalindrome(ListNode* head) {
        
        // brute force we just put all elements in a vector reverse the vector then we compare elemetns of vector to the `          ele in linked list if they are equal we move forward else we return false
        // if we have traversed the full linked list then we return true;
        ListNode * curr = head;
        while(curr!=NULL){
            ans.push_back(curr->val);
            curr = curr ->next;
        }
        reverse(ans.begin(),ans.end());
        curr = head;
        int i =0;
        while(curr !=NULL){
            if(ans[i] == curr->val){
                i++;
                curr = curr->next;
            }
            else{
                return false;
            }
        }
        return true;
    }
};