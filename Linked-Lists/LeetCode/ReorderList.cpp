/**
 * Question: https://leetcode.com/problems/reorder-list/
 * 
 * You are given the head of a singly linked-list. The list can be represented as:
 * 
 * L0 → L1 → … → Ln - 1 → Ln
 * Reorder the list to be on the following form:
 * 
 * L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
 * You may not modify the values in the list's nodes. Only nodes themselves may be changed.
 * 
 * Example 1:
 *     Input: head = [1,2,3,4]
 *     Output: [1,4,2,3]
 * Example 2:
 *     Input: head = [1,2,3,4,5]
 *     Output: [1,5,2,4,3]
 * 
 * Solution Discussion:
 *  > https://leetcode.com/problems/reorder-list/discuss/801883/Python-3-steps-to-success-explained
 * 
 * Simulation:
 *  
 *      1. Step 1: Find get mid node:
 *          Odd number of nodes:
 *            1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> NULL
 *                                ^
 *                                |
 *                                +--- Mid node                        
 *          Even number od nodes:
 *            1 -> 2 -> 3 -> 4 -> 5 -> 6 -> NULL
 *                           ^
 *                           |
 *                           +--- Mid Node    
 *                                  
 *     2. Step 2: Separate out the mid node and reverse the second half:
 *            
 *          head1 -> 1 -> 2 -> 3 -> 4 -> NULL
 *          head2 -> 7 -> 6 -> 5 -> NULL
 *                           
 *     3. Merge the two halves:
 *          
 *          head -> 1 -> 7 -> 2 -> 6 -> 3 -> 5 -> 4 -> NULL
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
    
    
ListNode* getMidNode(ListNode* head){

    ListNode *dummyHead = new ListNode(-1);
    dummyHead->next = head;
    
    ListNode *slow = dummyHead;
    ListNode *fast = head;

    while(fast!=NULL and fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    if(fast!=NULL){
        return slow->next;
    }

    return slow;
}

ListNode* reverse(ListNode *head){
    ListNode *fwd = head;
    ListNode *back = NULL;
    while(fwd!=NULL){
        ListNode *next_node = fwd->next;
        fwd->next = back;
        back = fwd;
        fwd = next_node;
    }
    return back;
}

public:
    void reorderList(ListNode* head) {

    ListNode* mid = getMidNode(head);

    ListNode *second = mid->next;
    mid->next = NULL;

    second = reverse(second);

    ListNode *dummyHead = new ListNode(-1);
    ListNode *tail = dummyHead;

    while(head!=NULL && second!=NULL){

        tail->next = head;
        head = head->next;
        tail= tail->next;

        tail->next = second;
        second = second->next;
        tail = tail->next;
    }

    if(head!=NULL){
        tail->next = head;
        tail = tail->next;
    }

    if(second!=NULL){
        tail->next = second;
        tail =tail->next;
    }

    head = dummyHead->next;
    }
};