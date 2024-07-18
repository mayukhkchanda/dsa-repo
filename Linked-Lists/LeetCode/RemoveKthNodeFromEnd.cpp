/**
 * Quesiton -> https://leetcode.com/problems/remove-nth-node-from-end-of-list/
 * 
 * Given the head of a linked list, remove the nth node from the end of the list and return its head.
 * Example 1:
 *   Input: head = [1,2,3,4,5], n = 2
 *   Output: [1,2,3,5]
 * Example 2:
 *   Input: head = [1], n = 1
 *   Output: []
 * Example 3:
 *   Input: head = [1,2], n = 1
 *   Output: [1]
 * 
 * Solution Discussion:
 *  > https://leetcode.com/problems/remove-nth-node-from-end-of-list/discuss/8804/Simple-Java-solution-in-one-pass
 * 
 * Intuition :
 *  > To remove the n-th node from the end we need to go the node before the n-th node that is
 *      to the (n+1)-th node from the end. Thus using the runner technique we go to the (n+1)-th node
 *      from the end. Then remove the n-th node.
 * 
 * Simulation:
 *                      
 *  n = 3. To remove the 3rd node from the end i.e. 5.
 * 
 *                       slow----+
 *  > dummyHead-> 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> NULL
 *                                                    ^---fast(using runner technique)
 *  > Remove node 5 now and return dummyHead->next.
 *  > dummyHead is used if we need to remove the 1st node. Thus we can finally return dummyHead->next.
 */

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int k = n+1; // to remove the nth node from END! go to the (n+1)th node from end
        
        // use a dummyHead
        ListNode *dummyHead = new ListNode(-1, head);
        
        //use the runner technique to go the k+1-th node from the end.
        ListNode *fast = head;
        while(--k && fast != NULL){
            fast = fast->next;
        }
        
        ListNode *slow = dummyHead;
        while(fast!= NULL){
            slow = slow->next;
            fast = fast->next;
        }
        
        // remove the n-th node 
        if(slow->next!=NULL){
            slow->next = slow->next->next;
        }else{
            slow->next = NULL;            
        }

        // return dummyHead->next that is pointing to the 1st node
        return dummyHead->next;
    }
};