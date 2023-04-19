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
    void solve(TreeNode * root,int x,int y,int parent,vector<pair<int,int>>& ans,int level){
        if(root == NULL){
            return;
        }
        solve(root->left,x,y,root->val,ans,level +1);
        if(root->val == x){
            ans.push_back({level,parent});
        }
        if(root->val == y){
            ans.push_back({level,parent});
        }
        solve(root->right,x,y,root->val,ans,level +1);
    }
    bool isCousins(TreeNode* root, int x, int y) {
        // lvl parent
        vector<pair<int,int>> ans;
        solve(root,x,y,-1,ans,0);
        if(ans[0].first !=ans[1].first){
            return false;
        }
        if(ans[0].second== ans[1].second){
            return false;
        }
        return true;
    }
};