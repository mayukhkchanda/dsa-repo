/**
 * Question : https://leetcode.com/problems/add-two-numbers/
 * 
 * You are given two non-empty linked lists representing two non-negative integers.
 * The digits are stored in reverse order, and each of their nodes contains a single digit. 
 * Add the two numbers and return the sum as a linked list.
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 * 
 * Example 1:
 *     Input: l1 = [2,4,3], l2 = [5,6,4]
 *     Output: [7,0,8]
 *     Explanation: 342 + 465 = 807.
 * Example 2:
 *     Input: l1 = [0], l2 = [0]
 *     Output: [0]
 * Example 3:
 *     Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
 *     Output: [8,9,9,9,0,0,0,1]
 * 
 * Simulation
 *   h1-> |    |    |    |
 *        1 -> 4 -> 3 -> X
 *        5 -> 6 -> X
 *   h2-> |    |    |    |
 *   d1-> 1    2    3    X
 *   d2-> 5    6    0    X
 *   car= 0    0    1    X
 *   sum= 6    10   4    X
 *   d -> 6    0    4    X
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
public:
    ListNode* addTwoNumbers(ListNode* head1, ListNode* head2) {
        
        // create a dummy head that would point to result
        ListNode *dummyHead = new ListNode(-1);

        // pointer that will add new digits to the list and move a place forward
        ListNode *tail = dummyHead;
        
        // to store sum and carry
        int sum = 0;
        int carry = 0;
        
        // iterate over the linked list untill the larger linked list is not exhausted
        while(head1 != NULL || head2 != NULL){
            
            // if we reach the end of a linked list then consider the corresponding digits to be 0
            int digit1 = head1 == NULL ? 0 : head1->val;
            int digit2 = head2 == NULL ? 0 : head2->val;
            
            // addition formula
            sum = digit1+digit2+carry;
            carry = sum/10;
            
            // add new node to the list and move the tail 1 place forward to
            // the new node
            tail->next = new ListNode(sum%10);
            tail = tail->next;
            
            // keep advancing the head pointers until both point to null
            head1 = head1 == NULL ? NULL : head1->next;
            head2 = head2 == NULL ? NULL : head2->next;
        }
        
        // if there's carry left then it should be added too
        if(carry > 0){
            tail->next = new ListNode(carry);
            tail = tail->next;
        }
        
        return dummyHead->next;
    }
};