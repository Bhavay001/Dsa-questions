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
    vector<int> rightSideView(TreeNode* root) {
        
        vector<int> ans;
        if(root==NULL){
            return ans;
        }

        queue<pair<TreeNode *,int>> q;
        map<int,int> mp;
        q.push({root,0});
        while(!q.empty()){
            TreeNode * node = q.front().first;
            int lvl = q.front().second;
            q.pop();
            
            mp[lvl] = node->val;

            if(node->left!=NULL){
                q.push({node->left,lvl+1});
            }
            if(node->right !=NULL){
                q.push({node->right,lvl+1});
            }

        }
        for(auto x:mp){
            ans.push_back(x.second);
        }
        return ans;
    }
};