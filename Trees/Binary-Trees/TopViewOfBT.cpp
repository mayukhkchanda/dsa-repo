/*
Question: https://www.geeksforgeeks.org/print-nodes-top-view-binary-tree/

struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution
{
    
    void storeNodes(Node* root, map<int, map<int, int>>& hashmap,
                    int vd, int hd) {
        if (root == NULL) return;

        hashmap[hd][vd] = root->data;
        storeNodes(root->left, hashmap, vd+1, hd-1);
        storeNodes(root->right, hashmap, vd+1, hd+1);
    }
    
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        map<int, map<int, int>> hashmap;
        storeNodes(root, hashmap, 0, 0);
        
        vector<int> res;
        
        for (auto x : hashmap) {
            // cout << x.first << " ";
            auto it = x.second.begin();
            res.push_back(it->second);
        }
        
        return res;
    }

};
