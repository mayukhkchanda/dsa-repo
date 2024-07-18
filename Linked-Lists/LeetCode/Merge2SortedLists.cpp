/**
 * Question -> https://leetcode.com/problems/merge-two-sorted-lists/
 * 
 * Merge two sorted linked lists and return it as a sorted list. The list should
 * be made by splicing together the nodes of the first two lists.
 * 
 * Example 1:
 *      Input: l1 = [1,2,4], l2 = [1,3,4]
 *      Output: [1,1,2,3,4,4]
 * Example 2:
 *      Input: l1 = [], l2 = []
 *      Output: []
 * Example 3:
 *      Input: l1 = [], l2 = [0]
 *      Output: [0]
 * 
 * Solution Discussion->
 *  > https://leetcode.com/problems/merge-two-sorted-lists/discuss/9735/Python-solutions-(iteratively-recursively-iteratively-in-place).
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
    
    void insert(ListNode * &head, ListNode * &tail){
        ListNode* next = head->next;
        
        head->next = tail->next;
        tail->next = head;
        tail = tail->next;
        head = next;
    }
    
public:
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
        
        ListNode *dummyHead = new ListNode(0, NULL);
        ListNode *tail = dummyHead;
        
        while(head1 != NULL && head2 != NULL){
            
            if(head1->val <= head2->val){
                insert(head1, tail);
            }else{
                insert(head2, tail);
            }
        }
        
        if(head1 != NULL){
            tail->next = head1;
        }
        else if(head2 != NULL){
            tail->next = head2;
        }
        
        return dummyHead->next;        
    }
};