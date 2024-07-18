/**
 * Q: https://leetcode.com/problems/diameter-of-binary-tree/
 * 
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 * 
 * Intuition:
 * > at each node we return the max height from that node to either the right or left sub-tree
 *   and the maximum of tree diameter seen to the right , left sub-tree & passing through the
 *   current node. At the end, the second value returned has the result
 * > at null node we return 0,0 
 * 
 * 
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */

function helper(root) {
    if (!root) {
      return [0, 0]; // max height either to left or right, root_max_seen
    }
    
    let left = helper(root.left);
    let right = helper(root.right);
    
    root_max = left[0] + right[0];
    
    return [Math.max(left[0], right[0])+1, Math.max(root_max, Math.max(left[1], right[1]))];    
}

var diameterOfBinaryTree = function(root) {
    res = helper(root);
    return res[1];
};