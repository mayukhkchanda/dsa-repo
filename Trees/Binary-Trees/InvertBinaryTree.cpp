/**
 * Question: https://leetcode.com/problems/invert-binary-tree/
 * 
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
    
    // DFS 
    TreeNode* invertDFS(TreeNode* root) {
        if (root == NULL) return root;
        
        TreeNode* left = invertTree(root->left);
        TreeNode* right = invertTree(root->right);
        
        root->right = left;
        root->left = right;
        return root;
    }
    
    void swapChilds(TreeNode* root) {
        TreeNode* left = root->left;
        root->left = root->right;
        root->right = left;
    }
    
    TreeNode* invertBFS(TreeNode* root) {
        if (root == NULL) return root;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node->left != NULL) q.push(node->left);
            if (node->right != NULL) q.push(node->right);
            
            swapChilds(node);
        }
        
        return root;
    }
    
public:
    TreeNode* invertTree(TreeNode* root) {
        // return invertDFS(root);
        return invertBFS(root);
    }
};