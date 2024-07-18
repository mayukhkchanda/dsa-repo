/**
 * Question: https://practice.geeksforgeeks.org/problems/construct-tree-from-preorder-traversal/1#
 * 
 */
 
class Node{
    public:
        int data;
        Node *left;
        Node *right;
        
        Node(int data){
            this->data = data;
        }
}
 
Node* buildTreeUtil(int n, int pre[], char preLN[], int &idx){
    
    if( idx >= n ) return NULL;
    
    Node *node = new Node(pre[idx]);
    
    if( preLN[idx] == 'L' ) return node;
    
    ++idx;
    node->left = buildTreeUtil(n, pre, preLN, idx);
    
    ++idx;
    node->right = buildTreeUtil(n, pre, preLN, idx);
    
    return node;
}


Node *constructTree(int n, int pre[], char preLN[])
{
    if(n == 0) return NULL;
    
    int idx =0 ;
    return buildTreeUtil(n, pre, preLN, idx);
}

