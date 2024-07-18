/**
 * Question: https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/
 * 
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    
    ListNode* current;
    
    TreeNode* buildTree(int start, int end) {
        if (start > end) return NULL;
        
        int mid = start + ((end - start) / 2);
        
        
        TreeNode* left = buildTree(start, mid - 1);
        
        TreeNode* root = new TreeNode(current->val);
        
        current = current->next;
        
        TreeNode* right = buildTree(mid + 1, end);
        
        root->left = left;
        root->right = right;
        
        return root;
    }
    
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == NULL) return NULL;
        int size = 0;
        
        ListNode* temp = head;
        current = head;
        while (temp != NULL) {
            temp = temp->next;
            size++;
        }
        
        return buildTree(1, size);
    }
};