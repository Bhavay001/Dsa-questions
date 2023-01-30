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
    void finalans(TreeNode* root, int low, int high,int &ans){
        if(root==NULL){
            return;
        }
        if(root->val >= low && root->val <=high){
            ans += root->val;
        }
        finalans(root->left,low,high,ans);
        finalans(root->right,low,high,ans);
    }
    
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root==NULL){
            return 0;
        }
        int ans = 0;
        finalans(root,low,high,ans);
        return ans;
    }
};