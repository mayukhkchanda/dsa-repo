/**
 * Question: https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/
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
    
    TreeNode* LCA(TreeNode* root, int a, int b) {
        if (root == NULL) return root;
        
        if (root->val == a || root->val == b) return root;
        
        TreeNode* left = LCA(root->left, a, b);
        TreeNode* right = LCA(root->right, a, b);
        
        if (left != NULL && right != NULL) return root;
        return left != NULL ? left : right;
    }
    
    int level(TreeNode* root, int target, int lvl) {
        if (root == NULL) return 0;
        
        if (root->val == target) return lvl;
        
        int left = level(root->left, target, lvl+1);
        int right = level(root->right, target, lvl+1);
        
        return max(left, right);
    }
    
    bool getPath(TreeNode* root, int target, string &str) {
        if (root == NULL) return false;
        
        
        if (root->val == target) return true;
        
        str.push_back('L');
        if(getPath(root->left, target, str)) return true;
        str.pop_back();
        
        str.push_back('R');
        if(getPath(root->right, target, str)) return true;
        str.pop_back();
        
        return false;        
    }
    
    
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* lca = LCA(root, startValue, destValue);
        string startPath = "";
        string destPath = "";
        
        if (lca == NULL) return startPath;
        
        int lvl = level(lca, startValue, 0);
        
        while(lvl > 0) {
            startPath += 'U';
            lvl--;
        } 
        
        getPath(lca, destValue, destPath);
        
        return startPath + destPath;
    }
};