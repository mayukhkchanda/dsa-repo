//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
/**
 * Question: https://www.geeksforgeeks.org/level-order-traversal-in-spiral-form/#:~:text=Spiral%20Order%20traversal%20of%20binary%20tree%20is%201,Worst%20case%20occurs%20in%20case%20of%20skewed%20trees.
 * */
// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};
// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

vector<int> findSpiral(Node *root);

// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


int main() {
    int t;
    string  tc;
    getline(cin,tc);
    t=stoi(tc);
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);

        vector<int> vec = findSpiral(root);
        for(int x : vec)
        cout<<x<<" ";
        cout << endl;
    }
    return 0;
}



// } Driver Code Ends


/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */


//Function to return a list containing the level order traversal in spiral form.
vector<int> findSpiral(Node *root)
{
  
    stack<Node*> leftToRightStk;
    stack<Node*> rightToLeftStk;
    vector<int> res;
    int dir = 1; // 0 -> left to right | 1 -> right to left
    
    if (root == NULL) return res;
    
    rightToLeftStk.push(root);
    
    while(!leftToRightStk.empty() || !rightToLeftStk.empty()) {
        
        if (dir) {
            // right to left
            Node* head = rightToLeftStk.top();
            rightToLeftStk.pop();
            res.push_back(head->data);
            if (head->right != NULL) {
                leftToRightStk.push(head->right);
            }
            if (head->left != NULL) {
                leftToRightStk.push(head->left);
            }
            if (rightToLeftStk.empty()) dir = 0;
        } else {
            Node* head = leftToRightStk.top();
            leftToRightStk.pop();
            res.push_back(head->data);
            if (head->left != NULL) {
                rightToLeftStk.push(head->left);
            }
            if (head->right != NULL) {
                rightToLeftStk.push(head->right);
            }
            if (leftToRightStk.empty()) dir = 1;
        }
        
    }
    
    return res;    
}



