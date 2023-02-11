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
        if(root==NULL){
            return 0;
        }
        
        queue<pair<TreeNode *,long long int >> q;
        long long width = 0;
        
        q.push({root,0});
      
        while(!q.empty()){
            int size = q.size();
            int minind = q.front().second;
            long long first,last;
            for(int i =0;i<size;i++){
                TreeNode * node = q.front().first;
                // this is done so that instead of storing elements index as 1 2 3 4 5
                // here now it has index starting from begining for each lvl
                long long index = q.front().second - minind;
                q.pop();
                if(i == 0){
                    first = index;
                }
                if(i==size-1){
                   last = index;
                }

                if(node->left!=NULL){
                    q.push({node->left,2*index+1});
                }

                if(node->right!=NULL){
                    q.push({node->right,2*index+2});
                }
                width = max(width,last-first +1);
            }
        }
        return width;
        
    }
};