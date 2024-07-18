/* Delete node in a prefix trie: https://practice.geeksforgeeks.org/problems/trie-delete/1
Node is as follows:
struct trie_node
{
    int value; // non zero if leaf
    trie_node_t *children[ALPHABET_SIZE];
};*/
class Solution{
    
    bool hasNoChilds(trie_node_t* root) {
        for (int i=0; i<26; i++) {
            if (root->children[i]) return false;
        }    
        return true;
    }
    
    trie_node_t* remove(trie_node_t* root, char key[], int depth, int n) {
        if (root == NULL) return root;
        
        bool isEmpty = hasNoChilds(root);

        // reached the end of word
        if (depth == n) {
            
            // need to demark this node as EOW(end of word) node
            if (root->value != 0)
                root->value = 0;
            
            // if there are no further childs of this node,
            // then we can delete this node
            if (isEmpty) {
                delete(root);
                root = NULL;
            }
            return root;
        }
        
        // else recur on the remaining characters
        root->children[key[depth]-'a'] = remove(root->children[key[depth]-'a'],
                                                key, depth+1, n);
        
        // if the root node is not EOW node and there are no childrens
        // for this node, then we need to remove this node
        if (root->value != 0 && isEmpty) {
            delete(root);
            root = NULL;
        }
        
        return root;
    }
    
    
    int keyLength(char key[]) {
        int i = 0;
        while (key[i] != '\0') i++;
        return i;
    }
    
  public:
  void deleteKey(trie_node_t *root, char key[])
  {
        int size = keyLength(key);
        
        remove(root, key, 0, size);
        
  }
};