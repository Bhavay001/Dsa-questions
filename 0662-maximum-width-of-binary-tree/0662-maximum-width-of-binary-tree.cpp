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
    int widthOfBinaryTree(TreeNode* root) {
        
        if(root == NULL){
            return 0;
        }
        long long ans = 0;
        queue<pair<TreeNode *,int>> q;
        q.push({root,0});
        
        while(!q.empty()){
            int n = q.size();
            long long first , last;
            int mmin = q.front().second; // this is the first nodes index in the level
            for(int i =0;i<n;i++){
                TreeNode * node = q.front().first;
                // this is done to avoid overflow
                long long curr_id = q.front().second - mmin; // curr nodes id by subracting mmin
                q.pop();
                
                if(i ==0){
                    first = curr_id;
                }
                if(i == n-1){
                    last = curr_id;
                }
                if(node ->left){
                    q.push({node->left, curr_id*2+1});
                }
                if(node ->right){
                    q.push({node->right,curr_id*2+2});
                }
            }
            ans = max(ans,last-first+1);
        }
        return ans;
    }
};