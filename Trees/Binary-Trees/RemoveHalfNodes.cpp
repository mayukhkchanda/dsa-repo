/*

Question: https://www.geeksforgeeks.org/given-a-binary-tree-how-do-you-remove-all-the-half-nodes/

Node is as follows:
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

// Return the root of the modified tree after removing all the half nodes.
Node *RemoveHalfNodes(Node *root)
{
   if (root == NULL) return root;
   
   Node* left = RemoveHalfNodes(root->left);
   Node* right = RemoveHalfNodes(root->right);
   root->left = left;
   root->right = right;
   if ((root->left != NULL & root->right != NULL)
        || (root->left == NULL & root->right == NULL)) return root;
   free(root);
   return left != NULL ? left : right;
   
}