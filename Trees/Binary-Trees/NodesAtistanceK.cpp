/**
 * Question: All Nodes Distance K in Binary Tree
 * Link: https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/
 * 
 * Good Discussion on topics:
 *  > Using hashmap in O(n) time & space:
 *      https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/discuss/143798/1ms-beat-100-simple-Java-dfs-with(without)-hashmap-including-explanation
 *  > In O(n) time & O(log n) space:
 *      https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/discuss/143886/Java-O(1)-space-excluding-recursive-stack-space
 * 
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    // unordered_map<TreeNode*, int> hashmap;
    // int findParentDistances(TreeNode* root, TreeNode* target) {
        
//         if (root == NULL) return -1;
        
//         if (root == target) {
//             hashmap.insert({root, 0});
//             return 0;
//         }
        
//         int left = findParentDistances(root->left, target);
        
//         if (left >= 0) {
//             hashmap.insert({root, left+1});
//             return left+1;
//         }
        
//         int right = findParentDistances(root->right, target);
//         if (right >= 0) {
//             hashmap.insert({root, right+1});
//             return right+1;
//         }
        
//         return -1;
    // }  
    // void findNodes(TreeNode* root, vector<int> &res, int k, int depth) {
        
//         if (root ==  NULL) return;
        
//         int seenDepth = depth;
//         if (hashmap.find(root) != hashmap.end()) seenDepth = hashmap.at(root);
        
//         if (seenDepth == k) {
//             res.push_back(root->val);
//         }
        
//         findNodes(root->left, res, k, seenDepth+1);
//         findNodes(root->right, res, k, seenDepth+1);
//     }
    
    
    
    // need to get the distance from target node to the nodes above, so return int value
    int findNodes(TreeNode* root, TreeNode* target,
                  vector<int> &res, int k, int distance) {
        
        if (root == NULL) return 0;
        
        // if we see the distance from target node to it's child node equals k, then
        // add it to the result
        if (distance == k) {
            res.push_back(root->val);
            return 0;
        }
        
        int left = 0;
        int right = 0;
        
        // if we reach the target node, then start adding the distance from that node
        // -OR- if we have already found the target node then we need to keep adding
        // the distance(from target node) as we go down
        if (root == target || distance > 0) {
            left = findNodes(root->left, target, res, k, distance+1);
            right = findNodes(root->right, target, res, k, distance+1);
        } 
        // else we have not found the target node yet and donot add the distance instead
        // we keep the distance as 0 till we find the node
        else {
            left = findNodes(root->left, target, res, k, distance);
            right = findNodes(root->right, target, res, k, distance);
            // if (left > 0) right = findNodes(root->right, target, res, k, left + 1);
            // else right = findNodes(root->right, target, res, k, distance);
        }
        
        // if we see that the current node is at distance k from target node either
        // to it's right or left then we add this node to the result also
        if (left == k || right == k) {
            res.push_back(root->val);
        }
        
        // if the target node was found to the right sub-tree of current node then, we
        // need to re-propagate the distance of target node to current node to the left
        // sub-tree & vice versa
        if (right > 0) {
            findNodes(root->left, target, res, k, right+1);
        }
        if (left > 0) {
            findNodes(root->right, target, res, k, left+1);
        }
        
        // if we've found the target, then after all the sub-tree operations are done
        // we return 1 to it's parent to signify that we've found the target
        if (root == target) return 1;
        
        //  if we've found the target node in either the left or right sub-tree, then
        //  we return the distance from target node to the current node + 1, so
        //  that the node above get to know the distance
        if (left > 0 || right > 0) {
            return left > 0 ? left+1 : right+1;
        }
        
        // else the target node was not found in either the left or right sub-tree of the
        // current node & hence we return 0
        return 0;
    }

public:
    // vector<int> distanceKWithHashmap(TreeNode* root, TreeNode* target, int k) {
//         int found = findParentDistances(root, target);
//         vector<int> res;
//         if (found == -1) return res; 
//         if (k == 0) {
//             res.push_back(target->val);
//         } else {
//             findNodes(root, res, k, hashmap.at(root));
//         }      
//         return res;
//     }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        vector<int> res;
        int distance = 0;
        
        if (k == 0) {
            res.push_back(target->val);
        } else {
            findNodes(root, target, res, k, distance);
        }
        
        return res;
    }
};