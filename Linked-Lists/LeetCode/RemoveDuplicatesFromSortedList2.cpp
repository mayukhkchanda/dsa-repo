/**
 * Question: https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
 * 
 * Given the head of a sorted linked list, delete all nodes that have duplicate numbers, 
 * leaving only distinct numbers from the original list. Return the linked list sorted as well.
 * 
 * Example 1:
 *     Input: head = [1,2,3,3,4,4,5]
 *     Output: [1,2,5]
 * Example 2:
 *     Input: head = [1,1,1,2,3]
 *     Output: [2,3]
 * 
 * Solution Discussion:
 *  > https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/discuss/28335/My-accepted-Java-code/27344
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
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
        ListNode *dummyHead = new ListNode(-1, head);
        ListNode *tail =dummyHead;
        
        while(tail!=NULL && tail->next!=NULL ){
            
            ListNode *walker = tail->next->next;
            
            while( walker!=NULL && walker->val == tail->next->val){
                walker = walker->next;
            }
            
            // if the walker has moved then there are duplicates
            if( tail->next->next != walker){
                // remove them and dont move tail to the next node
                tail->next = walker;
            }else{
                // else there are no duplicates and so move tail to the next node
                tail = tail->next;
            }
        }
        
        return dummyHead->next;
    }
};