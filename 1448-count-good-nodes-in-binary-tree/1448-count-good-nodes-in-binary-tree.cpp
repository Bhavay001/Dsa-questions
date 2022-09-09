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
    void preorder(TreeNode *root, int &goodnode, int max){
        if(root==NULL){
            return;
        }
        if(root->val>=max){
            goodnode++;
            max = root->val;
        }
        preorder(root->left, goodnode, max);
        preorder(root->right, goodnode, max);
    }
    int goodNodes(TreeNode* root) {
        int goodnode = 0;
        int max = INT_MIN;
        vector<int> ans;
        preorder(root, goodnode, max);
        return goodnode;
    }
};