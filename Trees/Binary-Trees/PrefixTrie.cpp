/**
 * Q: https://leetcode.com/problems/implement-trie-prefix-tree/
 * Prefix Trie
 * */

class Node{
    public:
        char ch;
        // unordered_map<char, Node*> map;
        vector<Node*> map;
        bool isTerminal;
        Node(char ch) {
            this->ch = ch;
            
            vector<Node*> temp(26, NULL);
            this->map = temp;
            this->isTerminal = false;
        }
};

class Trie {
    
    Node* root;
    
public:
    Trie() {
        root = new Node('\0');
        root->isTerminal = false;
    }
    
    void insert(string word) {
        Node* temp = root;
        for (char ch : word) {
            // if (temp->map.find(ch) == temp->map.end()) {
            //     temp->map[ch] = new Node(ch);
            //     temp->map[ch]->isTerminal = false;
            // }
            if (temp->map[ch-'a'] == NULL) {
                temp->map[ch-'a'] = new Node(ch);
            }
            temp = temp->map[ch-'a'];
        }
        temp->isTerminal = true;
    }
    
    bool search(string word) {
        Node* temp = root;
        for (char ch : word) {
            // if there's no word that has the character 'ch' in it's prefix,
            // then we can surely say the word doesnot exists
            // if (temp->map.find(ch) == temp->map.end()) {
            //     return false;
            // }
            if (temp->map[ch-'a'] == NULL) return false;
            // else we keep following the prefix
            temp = temp->map[ch-'a'];
        }
        
        // if the last node is a terminal node, then we can say that the word exists
        return temp->isTerminal;
    }
    
    bool startsWith(string prefix) {
        Node* temp = root;
        int len = 0;
        for (char ch : prefix) {
            // if (temp->map.find(ch) == temp->map.end()) return false;
            if (temp->map[ch-'a'] == NULL) return false;
            temp = temp->map[ch-'a'];
            len++;
        }
        return len == prefix.size();
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */