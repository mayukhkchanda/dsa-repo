/**
 * Question: https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/
 * Solution: https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/discuss/286725/JavaC%2B%2BPython-Revered-Inorder-Traversal
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
    /**
     * using post-order traversal, we start from the right most node of the tree
     * and keeping returning the sum of a sub-tree to its parent. Since we traverse
     * right side first, the sum obtained from the right sub-tree is sent to the 
     * left sub-tree. Finally, we can return the sum of root value, left and right 
     * sub-tree.
     * 
     * Note: Initially, we call with sum = 0, so all the right most nodes will be called
     * with sum 0
     * */
    int convert(TreeNode* root, int sum) {
        
        if (root == NULL) return 0;
        
        // go to the right sub-tree first and calulate the sum
        int right_sum = convert(root->right, sum);
        
        // store the returned value for later processing
        int root_val = root->val;  
        
        // convert root node to greater sum node
        root->val += right_sum + sum;
        
        // pass this root value to left sub-tree
        int left_sum = convert(root->left, root->val);
        
        // finally return the total sum
        return right_sum + left_sum + root_val; 
    }
    
    
public:
    TreeNode* bstToGst(TreeNode* root) {
        convert(root, 0);
        return root;
    }
};