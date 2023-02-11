/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode * findAns(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root==NULL || root==p || root==q){
            return root;
        }
        TreeNode * left = findAns(root->left,p,q);
        TreeNode * right = findAns(root->right,p,q);
        
        if(left !=NULL && right !=NULL){
            return root;
        }
        else if(left!=NULL && right== NULL){
            return left;
        }
        else{
            return right;
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL){
            return NULL;
        }
        
        return findAns(root,p,q);
    }
};