/**
 * Question : https://leetcode.com/problems/sort-list/
 * 
 * Given the head of a linked list, return the list after sorting it in ascending order.
 * 
 * Example 1:
 *     Input: head = [4,2,1,3]
 *     Output: [1,2,3,4]
 * Example 2:
 *     Input: head = [-1,5,3,4,0]
 *     Output: [-1,0,3,4,5]
 * Example 3:
 *     Input: head = []
 *     Output: []
 * 
 * */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    
    // get the mid node of the linked list. Returns the first mid node if even # of elements
    // else returns the node before the mid node if odd # of elements.
    ListNode* midNode(ListNode *head){
        ListNode *dummyHead = new ListNode(-1, head);
        
        ListNode *slow = dummyHead;
        ListNode *fast = dummyHead->next;
        
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
    
    // merge 2 linked lists
    ListNode* merge(ListNode *left, ListNode *right){
        
        ListNode* newHead = new ListNode(-1);
        ListNode* tail = newHead;
        
        while(left != NULL && right!=NULL){
            
            if(left->val <= right->val){
                tail->next = new ListNode(left->val);
                left = left->next;
            }else{
                tail->next = new ListNode(right->val);
                right = right->next;
            }
            
            tail = tail->next;
        }
        
        if(left != NULL){
            tail->next = left;
        }
        else if(right != NULL){
            tail->next = right;
        }
        
        return newHead->next;
    }
    
    
public:
    ListNode* sortList(ListNode* head) {
        // base case 1 or 0 nodes
        if(head == NULL || head->next == NULL){
            return head;
        }
        
        // find the mid node(will get the mid node incase of odd # elements and 
        // the node before mid node incase of even number of elements)
        ListNode *mid = midNode(head);
        
        // get the left and right head nodes
        ListNode *left = head;
        ListNode *right = mid->next;
        mid->next = NULL;
        
        // sort the left and right part recursively
        left = sortList(left);
        right = sortList(right);
        
        // merge the left and right part
        head = merge(left, right);
        
        return head;
    }
};