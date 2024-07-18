/*
Q: https://practice.geeksforgeeks.org/problems/cousins-of-a-given-node/1
// A Binary Tree Node
struct Node
{
	int data;
	Node* left;
	Node* right;
};*/

class Solution
{
    public:
    vector<int> printCousins(Node* root, Node* target)
    {
        
        queue<Node*> q;
        
        q.push(root);
        q.push(NULL);
        
        bool isFound = false;
        
        while (!q.empty()) {
            
            Node* current =  q.front();
            q.pop();
            
            if (current->left != NULL && current->right != target
                && current->left != target)
                q.push(current->left);
                
            if (current->right != NULL && current->left != target
                && current->right != target)
                q.push(current->right);
            
            
            if (current->right == target || current->left == target)
                isFound = true;
                
                
            if (!q.empty() && q.front() == NULL) {
                q.pop();
                if (isFound) break;
                
                if (!q.empty() && q.front() != NULL) q.push(NULL);
            }
        }
        
        
        vector<int> res;
        
        if (q.empty()) {
            res.push_back(-1);
        }
        
        while(!q.empty()) {
            if (q.front() != NULL) {
                res.push_back(q.front()->data);
            }
            q.pop();
        }
        
        return res;
    }
    
};