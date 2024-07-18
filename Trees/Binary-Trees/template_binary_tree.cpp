#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node {
    public:
        int val;
        Node* left;
        Node* right;
        Node(int val) {
            this->val = val;
            this->left = NULL;
            this->right = NULL;
        }
};

Node* buildTree() {
    queue<Node*> q;
    int val;
    cin >> val;
    Node* root = new Node(val);
    q.push(root);
    while(cin >> val) {
        Node* top = q.front();
        q.pop();
        Node* left = NULL;
        Node* right = NULL;
        
        left = val != -1 ? new Node(val) : NULL;
        if (cin >> val) {
            right = val != -1 ? new Node(val) : NULL;
        }
        top->left = left;
        top->right = right;
        if(left != NULL) q.push(left); 
        if(right != NULL) q.push(right); 
    }
    return root;
}

void preorder(Node* root) {
    if (root == NULL) return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
	Node* root = buildTree();
	preorder(root);
	return 0;
}
