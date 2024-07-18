/**
 * Q: https://leetcode.com/problems/recover-binary-search-tree/
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
    
    TreeNode* prev = NULL;
    TreeNode* first = NULL;
    TreeNode* second = NULL;
    
    void inorderRecursive(TreeNode* curr) {
        
        if (curr == NULL) return;
        
        
        inorderRecursive(curr->left);
        
        // as inorder of bst is an ascending order seq, hence if there is a previous node
        // whose value is greater than current node, then there is a wrong node
        if (prev != NULL && prev->val > curr->val) {
            
            /* if we are seeing this violation for the first time then, we know that the
                prev node is out of place. why? consider the below inorder example,
                    6 3 4 5 2.
                The first time we see, 6 > 3, hence the previous node is our first node
                that is out of place.
                The next time we see, 5 > 2, hence the curr node is our second node that
                is out of place.
                It could also happen that the 2 nodes are adjacent to each other, for eg:
                    3 1 4.
                For this, we should update the second element during the first time also.
            */
            if (first == NULL) first = prev;
            if (first != NULL) second = curr;
        }
        prev = curr;
        inorderRecursive(curr->right);
    }
    
    void morrisTraversal(TreeNode* root) {
        
        while(root != NULL) {
            
            if (root->left != NULL) {
                
                TreeNode* temp = root->left;
                while (temp->right != NULL && temp->right != root) temp = temp->right;
                
                if (temp->right == NULL) {
                    temp->right = root;
                    root = root->left;
                } else {
                    temp->right = NULL;
                    
                    if (prev != NULL && prev->val > root->val) {
                        if(first == NULL) first = prev;
                        second = root;
                    }
                    prev = root;
                    
                    root = root->right;
                }
                
                
            }
            else {
                if (prev != NULL && prev->val > root->val) {
                    if (first == NULL) first = prev;
                    second = root;
                }
                prev = root;
                
                root = root->right;
            }
            
        }
        
    }
    
public:
    void recoverTree(TreeNode* root) {
        
        // inorderRecursive(root);
        morrisTraversal(root);
        
        int temp = first->val;
        first->val = second->val;
        second->val = temp;
    }
};