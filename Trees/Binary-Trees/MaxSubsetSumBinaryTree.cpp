/*
Question: https://www.geeksforgeeks.org/maximum-sum-nodes-binary-tree-no-two-adjacent/

struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution{
    
    /**
     * return : pair of int where first value denotes max sum obtained by including the current node and excluding it's children,
     *          and second value denotes max sum obtained by excluding the current node
     * */
    pair<int, int> getMaxSumUtil(Node *root){
        if (root == NULL) return {0,0}; // {max value including node, max value excluding node}
        
        pair<int, int> left = getMaxSumUtil(root->left);
        pair<int, int> right = getMaxSumUtil(root->right);
        
        
        /**
         * If we consider a node, then we cannot consider it's direct child or parent, hence
         * at each node we are left with 2 choices i.e. to include the current node and exclude it's direct children(if any) 
         * or to exclude the current node's value and consider the max of the value of left sub-tree including the left-child
         * node and excluding the left-child node + max of value of right sub-tree including the right-child node and excluding
         * the right child node.
         * 
         * We return 2 values :
         *  1. Including the current node's value, this means the total sum would be:
         *      current node's value + max value of left-sub tree excluding the left-child node + max value of right-sub tree excluding the right-child node
         *  2. Excluding the current node's value, this means the total sum would be:
         *      max of(left sub-tree including left child, left sub-tree excluding left child) + max value of (right sub-tree including left child, right sub-tree excluding right child)
         *      
         * */
        pair<int, int> curr = { root->data+left.second+right.second , 
                            max(left.first,left.second)+max(right.first, right.second) } ;
                            
        return curr;
    }
    
  public:
    //Function to return the maximum sum of non-adjacent nodes.
    int getMaxSum(Node *root) 
    {
        pair<int, int> res = getMaxSumUtil(root);
        return max(res.first, res.second);
    }
};
