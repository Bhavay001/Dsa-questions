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

     int maxDepth(TreeNode* root,int &res) {
        if(root == NULL){
            return 0;
        }
        int lh = maxDepth(root->left,res);
        int rh = maxDepth(root->right,res);
        res = max(res, lh + rh);
         
        return 1 + max(lh,rh);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        maxDepth(root,res);
        return res;
    }
};