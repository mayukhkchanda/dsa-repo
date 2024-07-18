/**
 * Question: https://leetcode.com/problems/binary-tree-maximum-path-sum/
 * Solution Explanation: https://leetcode.com/problems/binary-tree-maximum-path-sum/discuss/389609/Full-Explanation-article-with-pseudo-code-Beats-JAVA-100-time-and-100-space-Solution
 * With Pictures: https://leetcode.com/problems/binary-tree-maximum-path-sum/discuss/603423/Python-Recursion-stack-thinking-process-diagram
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
    
    int res= INT_MIN;
    
    int maxPathSumUtil(TreeNode* root){
        if(root == NULL) return 0;
        
        int leftSubTreeMaxPathSum = maxPathSumUtil(root->left);
        int rightSubTreeMaxPathSum = maxPathSumUtil(root->right);
        
        int leftOnly = root->val + leftSubTreeMaxPathSum;
        int rightOnly = root->val + rightSubTreeMaxPathSum;
        int fullTree = root->val + leftSubTreeMaxPathSum + rightSubTreeMaxPathSum;
        
        int temp = max( max(root->val, leftOnly), max(rightOnly, fullTree) );
        res = max(res, temp);
        
        /** If there is a parent of this node, then we need to return a max path
            sum  value that includes the current node max of:
                1. the root itself 
                2. root + it's left sub-tree only
                3. root + it's right sub-tree only
        */
        return max(root->val, max(leftOnly, rightOnly));
    }
    
    
public:
    int maxPathSum(TreeNode* root) {
        maxPathSumUtil(root);
        return res;
    }
};