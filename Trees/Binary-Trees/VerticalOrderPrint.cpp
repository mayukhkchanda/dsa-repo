/**
 * question: https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
 * solution: https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/discuss/260502/C%2B%2B-BFSDFS* 
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
 * 
 * We use am ordered map to store the nodes ordered by first horizontal distance from the root
 * & second by the vertical distance from the root. Use a set to store the node with same x & y 
 * distance nodes in sorted order.
 * 
 */
class Solution {
    
    // DFS solution
    void traverseRecur(TreeNode* root, map<int, map<int, multiset<int>>> &nodes,
                        int x, int y) {
        if (root == NULL) return;
        
        // store the value of this node in the map sorted first by horizontal distance 
        // from the root & second by vertical distance from the root
        nodes[x][y].insert(root->val);
        
        traverseRecur(root->left, nodes, x-1, y+1);
        traverseRecur(root->right, nodes, x+1, y+1);
    }
    
    // BFS solution
    void traverseIter(TreeNode* root, map<int, map<int, multiset<int>>> &nodes,
                        int x, int y) {
        // queue to store the node & it's corresponding x & y co-ordinates from the root
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});
        
        while(!q.empty()) {
            pair<TreeNode*, pair<int, int>> node = q.front();
            q.pop();
            
            nodes[node.second.first][node.second.second].insert(node.first->val);
            
            if (node.first->left != NULL) {
                q.push({node.first->left, {node.second.first-1, node.second.second+1}});
            }
            if (node.first->right != NULL) {
                q.push({node.first->right, {node.second.first+1, node.second.second+1}});
            }
        }        
    }
    
    
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // store a node wrt to a specific x & y position of the node from the root
        // sorted in ascending order
        map<int, map<int, multiset<int>>> nodes;
        // traverseRecur(root, nodes, 0, 0);
        traverseIter(root, nodes, 0, 0);
        
        vector<vector<int>> res;
        
        for(auto x : nodes) {
            vector<int> temp;
            for(auto y : x.second) {
                temp.insert(temp.end(), y.second.begin(), y.second.end());
            }
            res.push_back(temp);
        }
        return res;
    }
};