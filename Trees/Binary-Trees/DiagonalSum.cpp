
/*
Question: https://www.geeksforgeeks.org/diagonal-sum-binary-tree/#:~:text=The%20diagonal%20sum%20in%20a%20binary%20tree%20is,is%20sum%20of%209%2C%2010%2C%2011%20and%2012.
struct Node{
    int data;
    Node *left,*right;
};
*/

/***
 * vd & hd -> vertical & horizontal distance of a node from root node
 * We can use the concept of row & columns in a matrix, mapping row
 * to vd & column to hd. 
 * 
 *                          1 (0, 0)
 *                        /   \
 *               (-1,1) 2       3 (1, 1)
 *                     /       /
 *             (-2,2) 4       5 (0, 2)
 * 
 *  Thus, mapping the nodes in a matrix form with their vd as row# 
 *  & hd as column#. we have:
 * 
 * (vd)  -2  -1  0   1   2(hd)
 *  -2                                        
 *  -1                            
 *   0           1              
 *   1        2      3       
 *   2    4       5                 
 *   
 *   Thus all the nodes in the same diagonal have the same value of (row-column)
 * 
 * */

void helper(Node* root, int vd, int hd, map<int, int>& sum) {
    
    if(root == NULL) return;
    
    sum[vd - hd] = sum[vd - hd] + root->data;
    
    helper(root->left, vd+1, hd-1, sum);
    helper(root->right, vd+1, hd+1, sum);
}


// O(n) time & 0(h + d) space where h is height of the tree and d is the # of diagonal of the tree
// needed for storing the diagonal sum in the map
vector<int> diagonalSum(Node* root) {
    map<int, int> sum;
    helper(root, 0, 0, sum);
    
    vector<int> res;
    for (auto entry : sum) {
        res.push_back(entry.second);
    }
    return res;
}



// O(n) time & space
vector<int> diagonalSum(Node* root) {
    vector<int> res;
    queue<Node*> q;
    
    int diagonal_sum = 0;
    int diagonalNodeCnt = 0;
    int diagonalNodeNum = 0;

    Node* head = root;
    
    while(head != NULL) {
        
        if (head->left != NULL) {
            // store the left node of at every node for later traversal
            q.push(head->left);
            
            // as every left node in the current diagonal will lie in the
            // next diagonal so we increase the count
            diagonalNodeCnt++;
        }
        
        // add the head's value to the current diagonal sum
        diagonal_sum += head->data;
        
        // move along the diagonal of the current root
        head = head->right;
        
        if (head == NULL) {
            // if we've reach the end of a diagonal, then we 
            // switch to the next diagonal node
            if (!q.empty()){
                head = q.front();
                q.pop();
            }
            
            // if we've traversed every left node of the current diagonal,
            // then we know that the front of the queue has the starting node
            // of the next diagonl. Hence we reset the diagonal_sum and the
            // diagonal node number
            if (diagonalNodeNum == 0) {
                res.push_back(diagonal_sum);
                diagonalNodeNum = diagonalNodeCnt;
                diagonalNodeCnt = 0;
                diagonal_sum = 0;
            }
            diagonalNodeNum--;
        }
    }


    return res;
}

