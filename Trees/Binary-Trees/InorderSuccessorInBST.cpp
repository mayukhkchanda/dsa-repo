/**
 * Q: https://practice.geeksforgeeks.org/problems/inorder-successor-in-bst/1
 * 
 * */
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution{
    bool targetFound = false;
    Node* successor = NULL;
    
    void helper(Node* root, Node* target) {
        if (root == NULL) return;
        helper(root->left, target);
        
        if (root == target) {
            targetFound = true;
            Node* right = root->right;  
            while(right != NULL) {
                successor = right;
                right = right->left;
            }
        }
        
        if (targetFound && root != target && successor == NULL)
            successor = root;
        
        if (successor != NULL) return;
        
        helper(root->right, target);
    }
    
  public:
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    Node * inOrderSuccessor(Node *root, Node *x)
    {
        helper(root, x);
        return successor;
    }
};