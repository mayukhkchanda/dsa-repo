/**
 * Question: 
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
    
    TreeNode* buildTree(vector<int>& nums, int start, int end) {
        if (start > end) return NULL;
        
        if (start == end) return new TreeNode(nums[start]);
        
        int mid = start + ((end - start) / 2) ;
        
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = buildTree(nums, start, mid - 1); // go left
        root->right = buildTree(nums, mid + 1, end); // go right
            
        return root;
    }
    
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildTree(nums, 0, nums.size() - 1);
    }
};