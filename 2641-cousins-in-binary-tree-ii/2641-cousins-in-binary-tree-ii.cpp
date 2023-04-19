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
    void bfs(TreeNode* root,vector<int>ans){
        queue<TreeNode*> q;
        q.push(root);
        root->val=0;
        int k=1;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode* front=q.front();
                q.pop();
                int sum=0;
                if(front->left){
                    q.push(front->left);
                    sum+=front->left->val;
                }
                if(front->right){
                    q.push(front->right);
                    sum+=front->right->val;
                }
                if(front->left){
                    front->left->val=ans[k]-sum;
                }
                if(front->right){
                    front->right->val=ans[k]-sum;
                }
            }
            k++;
        }
    }
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<int>ans;
        int sum=0;
        while(!q.empty()){
            int size=q.size();
            sum=0;
            for(int i=0;i<size;i++){
                TreeNode* front=q.front();
                sum+=front->val;
                q.pop();
                if(front->left){
                    q.push(front->left);
                }
                if(front->right){
                    q.push(front->right);
                }
            }
            ans.push_back(sum);
        }
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        bfs(root,ans);
        return root;
    }
};