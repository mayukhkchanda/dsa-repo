/**
 * Q: https://leetcode.com/problems/binary-tree-right-side-view/submissions/
 * 
 * Good links on discussion:
 *  > https://leetcode.com/problems/binary-tree-right-side-view/discuss/56012/My-simple-accepted-solution(JAVA)
 *  > https://leetcode.com/problems/binary-tree-right-side-view/discuss/56003/My-C%2B%2B-solution-modified-preorder-traversal
 *      > Good comment of above explanation- https://leetcode.com/problems/binary-tree-right-side-view/discuss/56003/My-C++-solution-modified-preorder-traversal/57586
 * 
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
     * the main idea in the below approach is that for each level we can only inculde 1 node
     * that is the visible node. so we first visit the right node & then visit the left node
     * at every level if there exists a right most node then it will get pushed in the list
     * and no other node in that level will be pushed any more.
     * 
     * To get the left view, we push the left node first & then the right node.
     * */
    void recursion(TreeNode* root, vector<int> &res, int level) {
        if (root == NULL) return;
        
        // if we didn't picked any node from this level yet, then this is our rightmost node 
        if (res.size() < level) res.push_back(root->val);
        
        // we visit the right node first & then the left node. this ensure that we always
        // visit the right most node at any level first 
        recursion(root->right, res, level+1);
        recursion(root->left, res, level+1);
    }
    
    /**
     * we do a BFS traversal on the tree & store the each node of a level in a queue.
     * We visit the left node before the right node and store the value of the last
     * node of a level.    
     * 
     * To get the left view, we push the right node first before the left node. This 
     * ensures that the left most node is pushed at the last of each level
    */
    void iterative(TreeNode* root, vector<int> &res) {
        if (root == NULL) return;
        queue<TreeNode*> q;
        
        q.push(root);
        int size = q.size(); // to store the # of nodes at each level
        
        //while there are nodes in the queue
        while(!q.empty() && size > 0) {
            TreeNode* curr = q.front();
            size--;
            q.pop();
            
            // we push the left node before the right node to ensure that the 
            // right-most node always comes at the last of the queue for each level
            if (curr->left != NULL) q.push(curr->left);
            if (curr->right != NULL) q.push(curr->right);
            
            // if size becomes 0, then we've reached the last node of a level,
            // which must be the rightmost node
            if (size == 0) {
                res.push_back(curr->val);
                size = q.size();
            }
        }        
    }
        
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        int level = 1;
        // recursion(root, res, level);
        iterative(root, res);
        return res;
    }
};