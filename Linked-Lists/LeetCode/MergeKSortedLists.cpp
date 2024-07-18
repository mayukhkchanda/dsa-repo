/**
 * Question: https://leetcode.com/problems/merge-k-sorted-lists/
 * 
 * You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
 * Merge all the linked-lists into one sorted linked-list and return it.
 * Example 1:
 *   Input: lists = [[1,4,5],[1,3,4],[2,6]]
 *   Output: [1,1,2,3,4,4,5,6]
 *   Explanation: The linked-lists are:
 *   [
 *     1->4->5,
 *     1->3->4,
 *     2->6
 *   ]
 *   merging them into one sorted list:
 *   1->1->2->3->4->4->5->6
 * Example 2:
 *   Input: lists = []
 *   Output: []
 * Example 3:
 *   Input: lists = [[]]
 *   Output: []
 * 
 * 
 * Intuition & Solution Discussion:
 *  > Repeatedly merge 2 lists at a time. The time complexity remains the same i.e. O(total number of nodes).
 *  > https://leetcode.com/problems/merge-k-sorted-lists/discuss/10531/Sharing-my-straightforward-C%2B%2B-solution-without-data-structure-other-than-vector
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
    
    ListNode* merge(ListNode *head1, ListNode *head2){
        
        ListNode *result = new ListNode(-1);
        ListNode *tail = result;
        
        while(head1!=NULL && head2!=NULL){
            if(head1->val <= head2->val){
                tail->next = head1;
                head1 = head1->next;
            }else{
                tail->next = head2;
                head2 = head2->next;
            }
            tail = tail->next;
        }
        
        if(head1!=NULL){
            tail->next = head1;
        }
        
        if(head2!=NULL){
            tail->next = head2;        
        }
        
        return result->next;
    }  
    
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        // ListNode *dummyHead = new ListNode(-1);
        ListNode *new_head = NULL;
        
        for(ListNode* head: lists){
            new_head = merge(head, new_head);
        }
        
        return new_head;        
    }
};