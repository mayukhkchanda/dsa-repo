/**
 * Q: https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
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
    
    stack<TreeNode*> stk;
    
public:
    void flattenRecursive(TreeNode* root) {
        if (root == NULL) return;
        
        
        /* store the right node of the root, in a stack to come back to it later.
            as we are doing a pre-order traversal, hence we store the left node's 
            referrence in the right pointer of root node.*/
        if (root->right != NULL)
            stk.push(root->right);
        
        root->right = root->left;
        /*  As we are doing a pre-order traversal, hence we keep traversing the left node
            until we find NULL. And keep storing the right nodes. */
        flatten(root->left);
        
        /* Once we reach a leaf node, we set the left pointer of root node to NULL.
            And the right node of this leaf node will be the last pushed node into
            the stack(as we are doing a pre-order traversal). */
        root->left = NULL;
        if (!stk.empty()) {
            root->right = stk.top();
            stk.pop();
        }
        
        /* Then, we should traverse from the right node of the pop node from the stack
            to traverse all the right nodes pushed into the stack. */
        flatten(root->right);
    }
    
    void flattenIter(TreeNode* root) {
        
        TreeNode* curr = root;
        
        while (curr != NULL) {
            if (curr->left != NULL) {
                TreeNode* pre = curr->left;
                while(pre->right != NULL) {
                    pre = pre->right;
                }
                pre->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            } 
            curr = curr->right;
        }
        
    }
    
    void flatten(TreeNode* root) {
        // flattenRecursive(root);
        flattenIter(root);
    }
    
};