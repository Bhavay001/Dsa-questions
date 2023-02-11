/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool checkSymmetric(TreeNode * p, TreeNode * q){
        if(p == NULL && q==NULL){
            return true;
        }
        if((p == NULL && q!= NULL) || (q==NULL && p!=NULL)){
            return false;
        }
        
        if(p->val != q->val){
            return false;
        }
       return p->val == q->val && checkSymmetric(p->left,q->right) && checkSymmetric(p->right,q->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(!root->left && !root->right){
            return true;
        }
        if(!root->left || !root->right){
            return false;
        }
        return checkSymmetric(root->left,root->right);
    }
};