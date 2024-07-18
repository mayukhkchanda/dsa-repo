/**
 * Question: https://leetcode.com/problems/linked-list-cycle-ii/
 * 
 * Given the head of a linked list, return the node where the cycle begins. If there is no cycle,
 * return null. There is a cycle in a linked list if there is some node in the list that can be 
 * reached again by continuously following the next pointer. Internally, pos is used to denote the
 * index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.
 * Do not modify the linked list.
 * Example 1:
 *     Input: head = [3,2,0,-4], pos = 1
 *     Output: tail connects to node index 1
 *     Explanation: There is a cycle in the linked list, where tail connects to the second node.
 * Example 2:
 *     Input: head = [1,2], pos = 0
 *     Output: tail connects to node index 0
 *     Explanation: There is a cycle in the linked list, where tail connects to the first node.
 * Example 3:
 *     Input: head = [1], pos = -1
 *     Output: no cycle
 *     Explanation: There is no cycle in the linked list.
 * 
 * Solution Discussion:
 *  > https://leetcode.com/problems/linked-list-cycle-ii/discuss/44781/Concise-O(n)-solution-by-using-C%2B%2B-with-Detailed-Alogrithm-Description
 *  > Cycle detection proof: https://www.keithschwarz.com/interesting/code/?dir=find-duplicate
 * */ 


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;
        
        bool hasCycle = false;
        
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast){
                hasCycle = true;
                break;
            }
        }
        
        if(!hasCycle){
            return NULL;
        }
        
        ListNode *finder = head;
        
        while(finder != slow){
            finder = finder->next;
            slow = slow->next;
        }
        
        return finder;
    }
};