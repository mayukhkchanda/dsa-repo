// Question: https://leetcode.com/problems/binary-tree-level-order-traversal/

/**
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
public:
    
    /**
     * 
     * Intuition:
     *   We use a queue to keep track of all the nodes and their childern. We use 'NULL' to keep track of when a level ends and a new level starts.
     *   
     * Approach:
     *  1. Insert the root node and 'NULL' into the deque.
     *  2. Always pop from the front of the deque and store the node to a vector. After that push it's childern back into the deque.
     *  3. If the front of the queue is "NULL", then we know that the current level has ended and a new level is starting. Thus, we 
     *      transfer the node to the result vector and clear the temp vector of it's contents. We pop out this 'NULL' from the front
     *      and push a new NULL into the back of the queue. This is because as the current level has ended that means all of the 
     *      child nodes of the nodes in the current level(if any) have been push into the deque and hence we push another 'NULL' to
     *      mark the end of the next(child) level nodes.
     *  4. If ever the front of the queue has 'NULL' even after all of the above steps, we know that the queue is empty expect for
     *      'NULL' in the queue and we stop execution. If this check is not performed then we would go into an infinite loop condition
     *      where we keep on inserting 'NULL' for each 'NULL' we see.
     * 
     * 
     * 
     * Simulation:
     *     
     *                             Tree:
     *                        root->3    <- level 0                                                
     *                             / \                                                     
     *                            9  20  <- level 1                                              
     *                              / \                                                             
     *                             15 7  <- level 2                                                               
     *                                                                                               
     *                                                                                             
     *                              
     *   deque:  X=>NULL
     *   poped -> 3  X   9 20  X 15  7  X
     * elements  +--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+
     *           |3 |X | 9|20|X |15|7 |X |X |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |
     *           +--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+
     *            ^  ^  ^  ^  ^  ^  ^  ^  +--9.'NULL' at front so we exit
     *            |  |  |  |  |  |  |  +--8.'NULL' so pop this out and push a new 'NULL'(yes it's redundant and can exit early at this point)
     *            |  |  |  |  |  |  +--7. No childs 
     *            |  |  |  |  |  +--6.No childs
     *            |  |  |  |  +--5.We see a NULL again so we pop this 'NULL' out and insert a new 'NULL' at the end
     *            |  |  |  +--4.pop this and push it's childs
     *            |  |  +--3.No childs
     *            |  +--2.Now we encounter a 'NULL', that means we reached the end of a the current level and all of this level's childern are-
     *            |      -pushed in to the deque. So we insert a new 'NULL' in the deque's end that will mark the end of the next level's nodes
     *            +--1.pop 3 and push it's children
     *                                                                                                  
     */     
    
    vector<vector<int>> levelOrder(TreeNode* root){
        
        deque<TreeNode*> que;
        
        vector<vector<int>> res;
        vector<int> temp;
        
        que.push_back(root);
        // a 'NULL' node is pushed to separate out the nodes at different level
        // Whenever we encounter a NULL node, we know that the current level has
        // ended and we have moved to the next level
        que.push_back(NULL);
        
        while( !que.empty() && que.front() != NULL ){
            
            TreeNode* node = que.front();
            que.pop_front();
            
            temp.push_back(node->val);
            
            // push left and right nodes of the current node if they're not NUll
            if(node->left != NULL)
                que.push_back(node->left);
            
            if(node->right != NULL)
                que.push_back(node->right);
            
            
            if( que.front() == NULL ){
                // if the front of the queue has a 'NULL', then we know that a 
                // level has ended, and we are moving to the next level.
                que.pop_front();
                                
                res.push_back(temp);
                temp = {};
                
                que.push_back(NULL);
            }
        }
        
        return res;
    }
    
    
    
//     vector<vector<int>> levelOrder(TreeNode* root) {
        
//         if(root == NULL) return {};
        
//         deque<pair<TreeNode*, int>> qu; // {TreeNode*, level}
        
//         qu.push_back({root, 0});
        
//         vector<vector<int>> res = {};
        
//         while( !qu.empty() ){
            
//             pair<TreeNode*, int> temp = qu.front();
//             qu.pop_front();
//             if(res.size() < temp.second+1){
//                 res.push_back({temp.first->val});
//             }else{
//                 res[temp.second].push_back( temp.first->val );
//             }

//             if(temp.first->left != NULL)
//                 qu.push_back({temp.first->left, temp.second+1});
            
//             if(temp.first->right != NULL)
//                 qu.push_back({temp.first->right, temp.second+1});
//         }
        
//         return res;
//     }
};