/**
 * Question: https://leetcode.com/problems/binary-search-tree-iterator/
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
class BSTIterator {
    
    stack<TreeNode*> stk;
    
public:
    BSTIterator(TreeNode* root) {
        insertLeftNodes(root);
    }
    
    int next() {
        TreeNode* curr = stk.top();
        stk.pop();
        int smallest = curr->val;
        insertLeftNodes(curr->right);
        return smallest;
    }
    
    bool hasNext() {
        return !stk.empty();
    }
    
    void insertLeftNodes(TreeNode* root) {
        while(root != NULL) {
            stk.push(root);
            root = root->left;
        }
    }
    
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */