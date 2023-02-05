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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> ans;
        
        if(root==NULL){
            return ans;
        }
        
        queue<TreeNode*> q;
        int flag = true;
        q.push(root);
        
        while(!q.empty()){
            int size = q.size();
            vector<int> level(size);
            for(int i =0;i<size;i++){
                TreeNode * front = q.front();
                q.pop(); 
                // int index = flag ? i : (size- 1 - i);
                int index = 0;
                if(flag == 1){
                    // i have to insert normally
                    index = i;
                }
                else if(flag == 0){
                    // we have to insert from the end
                    index = size - i - 1;
                }
                
                // we will now add the node at the index if the flag is true we move left to right
                // if flag is false we move from right to left so we cannot directly push in vector i have to insrt in indexes
                level[index] = front->val;
         
                if(front->left!=NULL){
                    q.push(front->left);
                }
                if(front->right !=NULL){
                    q.push(front->right);
                }
                
            }
            ans.push_back(level);
            flag = !flag;
        }
        return ans;
    }
};