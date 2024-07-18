/**
 * Question: https://www.interviewbit.com/problems/palindrome-list/
 * Leetcode: https://leetcode.com/problems/palindrome-linked-list/
 * 
 * Given the head of a singly linked list, return true if it is a palindrome.
 * Example 1:
 *     Input: head = [1,2,2,1]
 *     Output: true
 * Example 2:
 *     Input: head = [1,2]
 *     Output: false
 *
 * Solution Discussion:
 *  > https://leetcode.com/problems/palindrome-linked-list/discuss/64501/Java-easy-to-understand
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
    
    ListNode* getMidNode(ListNode *head){
        ListNode *dummyHead = new ListNode(-1, head);
        
        ListNode *slow = dummyHead;
        ListNode *fast = head;
        
        while(fast!=NULL and fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
    
    ListNode* reverse(ListNode *head){
        ListNode *fwd = head;
        ListNode *back = NULL;
        while(fwd!=NULL){
            ListNode *next_node = fwd->next;
            fwd->next = back;
            back =fwd;
            fwd=next_node;
        }
        return back;
    }
    
public:
    bool isPalindrome(ListNode* head) {
        ListNode *nodeBfrMid = getMidNode(head);
        
        ListNode *mid = nodeBfrMid->next;
        nodeBfrMid->next = NULL;
        mid = reverse(mid);
        
        while(mid!=NULL && head!=NULL){
            if(head->val != mid->val){
                return false;
            }
            mid = mid->next;
            head= head->next;
        }
        return true;
    }
};