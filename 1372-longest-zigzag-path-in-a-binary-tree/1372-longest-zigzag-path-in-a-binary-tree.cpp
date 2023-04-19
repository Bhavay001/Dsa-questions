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
    int maxlength = 0;
    
    // from left  => 0
    // from right => 1
    void solve(TreeNode * root, int dir,int currlength){
        if(root == NULL){
            return;
        }
        maxlength = max(maxlength,currlength);
        // dir 1 hui to add curr + 1 else 1
        solve(root->left,0,dir?currlength +1:1);
        
        // dir 0 hui to currlength + 1 else 1
        solve(root->right,1,dir?1:currlength +1);
       
    }
    int longestZigZag(TreeNode* root) {
        // since root is the top element we consider it has both incoming path left and right
        //  we consider 0 as left path and 1 as right path
        solve(root,0,0);
        solve(root,1,0);
        return maxlength;
        
    }
};