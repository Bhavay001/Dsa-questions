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
    

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL){
            return ans;
        }
        // node<vertical,level>>
        queue<pair<TreeNode *,pair<int,int>>> q;
        
        // vertical ,level, multiset(node)
        map<int, map<int,multiset<int>>> mp;
        q.push({root,{0,0}});
        while(!q.empty()){
            TreeNode * node = q.front().first;
            int hd = q.front().second.first;
            int lvl = q.front().second.second;
            q.pop();
            mp[hd][lvl].insert(node->val);
            
            if(node->left!=NULL){
                q.push({node->left,{hd-1,lvl+1}});
            }
            
            if(node->right!=NULL){
                q.push({node->right,{hd+1,lvl+1}});
            }
        }
        for(auto x:mp){
            vector<int> col;
            for(auto y:x.second){
                col.insert(col.end(),y.second.begin(),y.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};