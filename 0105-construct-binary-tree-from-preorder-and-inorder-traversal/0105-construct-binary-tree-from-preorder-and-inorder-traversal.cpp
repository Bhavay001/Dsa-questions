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
    
    TreeNode * tree(vector<int> & preorder, int preStart, int preEnd, vector<int> &inorder, int inStart, int inEnd , map<int,int> &mp){
        
        // base case as soon as the preorder or the inorder vector finishes we will return Null
        if(preStart > preEnd || inStart> inEnd){
            return NULL;
        }
        
        // as preorder is root left right we make the first element of preorder as root
        TreeNode * root = new TreeNode(preorder[preStart]);
        
        // we find the root element in the inorder vector
        int inorderindex = mp[root->val];
        // we will get the number of elements in the left tree
        int noOfElements = inorderindex - inStart;
        
        // now we will make the left of the root by taking the left of the inorder and the right of the root by 
        // the right of the inorder 
        // the new preorder will be the first n elements that are on the right of the root and roots right will be the              elements after the n elements till the end
        
        root->left = tree(preorder, preStart + 1, preStart + noOfElements, inorder , inStart, inorderindex -1, mp);
        root->right = tree(preorder, preStart + noOfElements+1,preEnd, inorder, inorderindex +1,inEnd,mp);
        
        return root;
    }
    
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        map<int,int> mp;
        for(int i =0;i<n;i++){
            mp[inorder[i]] = i;
        }
    
        // we will take 2 indexes for preorder and 2 indexes for inorder each will point to the start and end of their 
        // vectors
        TreeNode * root = tree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mp);
        return root;
        
    }
};