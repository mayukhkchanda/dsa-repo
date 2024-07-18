/**
 * Question: https://www.interviewbit.com/problems/sort-binary-linked-list/
 * Given a Linked List A consisting of N nodes.
 * The Linked List is binary i.e data values in the linked list nodes consist of only 0's and 1's.
 * You need to sort the linked list and return the new linked list.
 * Try to do it in constant space.
 * Example Input
 * Input 1:
 *  1 -> 0 -> 0 -> 1
 * Input 2:
 *  0 -> 0 -> 1 -> 1 -> 0
 * 
 * Example Output
 * Output 1:
 *  0 -> 0 -> 1 -> 1
 * Output 2:
 *  0 -> 0 -> 0 -> 1 -> 1
 * 
 * Example Explanation
 * Explanation 1:
 *  The sorted linked list looks like:
 *   0 -> 0 -> 1 -> 1
 * Explanation 2:
 *  The sorted linked list looks like:
 *   0 -> 0 -> 0 -> 1 -> 1
 * */


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::solve(ListNode* head) {

    ListNode *zeros = new ListNode(-1);
    ListNode *zeros_tail = zeros;
    
    ListNode *ones = new ListNode(-1);
    ListNode *ones_tail = ones;

    while(head != NULL){
        ListNode *next_node = head->next;

        if(head->val == 0){
            zeros_tail->next = head;
            zeros_tail = zeros_tail->next;
            zeros_tail->next = NULL;
        }else{
            ones_tail->next = head;
            ones_tail = ones_tail->next;
            ones_tail->next = NULL;
        }

        head = next_node;
    }

    zeros_tail->next = ones->next;

    return zeros->next;

}
