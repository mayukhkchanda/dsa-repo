#include<bits/stdc++.h>
using namespace std;

/**
 * Question: https://www.techiedelight.com/determine-binary-tree-can-converted-another-number-swaps-left-right-child/
 * 
 * Approach: For each node we can check if it's root node are the same & if either of the below conditions matches
 * 1. if the left sub-tree of 1 matches left sub-tree of 2 &&
 *   the right sub-tree of 1 matches right sub-tree of 2
 * 2. if the left sub-tree of 1 matches right sub-tree of 2 &&
 *   the right sub-tree of 1 matches left sub-tree of 2
 *   because then we can swap their children to make them equal
 * 
 * */

class Node
{
  public:
   int key;
   Node *left;
   Node *right;

   Node(int key){
       this->key = key;
       left = right  = NULL;
   }
};


bool equal(Node * root1, Node * root2){
    //Complete the Function
    if (root1 == NULL && root2 == NULL) return true;
    
    if ((root1 == NULL && root2 != NULL)
            || (root1 != NULL && root2 == NULL)) return false;
            
    // we can only swap the childrens of a node, hence if the
    // root node differs then we cannot swap it any other node
    if (root1->key != root2->key) return false;
    
    // if these 2 nodes are equal, then we check their
    // sub-tree for either of 2 conditions:
    //      1. if the left sub-tree of 1 matches left sub-tree of 2 &&
    //      the right sub-tree of 1 matches right sub-tree of 2
    bool sameSubtree = equal(root1->left, root2->left) && equal(root1->right, root2->right);
    // or,  2. if the left sub-tree of 1 matches right sub-tree of 2 &&
    //      the right sub-tree of 1 matches left sub-tree of 2
    //      because then we can swap their children to make them equal
    bool crossSubtree = equal(root1->left, root2->right) && equal(root1->right, root2->left);
    
    return sameSubtree || crossSubtree;
}