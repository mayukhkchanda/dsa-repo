/**
 * Question: https://leetcode.com/problems/rotate-list/
 *          https://www.interviewbit.com/problems/rotate-list/
 * 
 * Given the head of a linked list, rotate the list to the right by k places.
 * Example 1:
 *     Input: head = [1,2,3,4,5], k = 2
 *     Output: [4,5,1,2,3]
 * Example 2:
 *     Input: head = [0,1,2], k = 4
 *     Output: [2,0,1]
 * 
 * Solution Discussion:
 *  > https://leetcode.com/problems/rotate-list/discuss/22715/Share-my-java-solution-with-explanation
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
    
    // returns the size of the linked list
    int size(ListNode* head){
        int len = 0;
        while(head!=NULL){ 
            head=head->next;
            len++;
        }
        return len;
    }
    
public:
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(head == NULL || k==0) return head;
        
        // get the size of the linked list
        int len = size(head);

        // find the effective rotation
        int rotate = k%len;

        // if the effecive rotation is 0 then return head
        if(rotate == 0) return head;

        // Make a dummy head and point it to the start
        ListNode *dummyHead = new ListNode(-1);
        dummyHead->next = head;
        ListNode *tail = dummyHead;

        // go to the node before the node that needs to come first after rotation
        for(int i=0; i<len-rotate; i++){
            tail = tail->next;
        }

        // store the new head and point the new tail to null
        ListNode *new_head = tail->next;
        tail->next = NULL;

        // go to the end of the linked list
        tail = new_head;
        while(tail!=NULL && tail->next!=NULL){
            tail = tail->next;
        }

        // connect the tail to the previous head
        tail->next = dummyHead->next;

        return new_head;
    }
};

