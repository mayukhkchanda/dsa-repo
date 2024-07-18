/**
 * Q: https://practice.geeksforgeeks.org/problems/longest-common-prefix-in-an-array5129/1
 */
class Node {
    public:
        char ch;
        vector<Node*> map;
        bool isLeaf;
        Node(char ch) {
            this->ch = ch;
            this->isLeaf = false;
            
            vector<Node*> temp(26, NULL);
            map = temp;
            
        }
};
class Solution{
    Node* root = NULL;
    
    void insert(string word) {
        if (root == NULL) {
            root = new Node('\0');
        }    
        
        Node* temp = root;
        
        for (char ch : word) {
            if (temp->map[ch-'a'] == NULL) {
                temp->map[ch-'a'] = new Node(ch);
            }
            temp = temp->map[ch-'a'];
        }
        temp->isLeaf = true;
    }
    
    void buildTrie(string arr[], int N) {
        for (int i = 0; i < N; i++) {
            insert(arr[i]);
        }
    }
    int count(vector<Node*>& map) {
        int cnt = 0;
        for (Node* node : map) {
            if (node != NULL) cnt++;
        }
        return cnt;
    }
    string prefixLength(string first) {
        string prefix = "";
        
        Node* temp = root;
        
        for (char ch : first) {
            // at each node we check if there's a branch from this current
            // node. if there's a branch starting from this current node
            // then max prefix is till this node
            // see link -> https://www.geeksforgeeks.org/longest-common-prefix-using-trie/
            if (count(temp->map) != 1 || temp->map[ch - 'a'] == NULL) break;
            
            // if there's no branch from this node then we move the next node
            // since the count is only 1, we know that ch is the next node
            prefix += ch;
            temp = temp->map[ch - 'a'];
        }
        
        return prefix == "" ? "-1" : prefix;
    }
    
  public:
    
    string longestCommonPrefix (string arr[], int N)
    {
        
        buildTrie(arr, N);
        
        // the max length of the longest prefix can be less than or equal to
        // the length of smallest string the arr
        int smallestStringIdx = 0;
        int minLength = INT_MAX;
        for (int i=0; i<N; i++) {
            if (arr[i].size() < minLength) {
                minLength = arr[i].size();
                smallestStringIdx = i;
            }
        }
        
        return prefixLength(arr[smallestStringIdx]);
    }
};