/**
 * Question: https://leetcode.com/problems/maximum-depth-of-binary-tree/
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
    
    int maxDepthRecur(TreeNode *root){
        if(root == NULL) return 0;
        int leftDepth = maxDepthRecur(root->left);
        int rightDepth = maxDepthRecur(root->right);
        return max(leftDepth, rightDepth)+1;
    }
    
    int maxDepthIter(TreeNode *root){
        stack<TreeNode*> nodeStk;
        stack<int> depthStk;
        
        nodeStk.push(root);
        depthStk.push(1);
        
        int maxDepth = 0;
        
        while(!nodeStk.empty() && nodeStk.top() != NULL){
            
            TreeNode *node = nodeStk.top();
            nodeStk.pop();
            
            int depth = depthStk.top();
            depthStk.pop();
            
            if(node->left == NULL && node->right == NULL){
                maxDepth = max(maxDepth, depth);
            }
            
            if(node->left != NULL){
                nodeStk.push(node->left);
                depthStk.push(depth+1);
            }
            
            if(node->right != NULL){
                nodeStk.push(node->right);
                depthStk.push(depth+1);
            }   
        }
        
        return maxDepth;
    }
    
public:
    int maxDepth(TreeNode* root) {
        // return maxDepthRecur(root);
        return maxDepthIter(root);
    }
};