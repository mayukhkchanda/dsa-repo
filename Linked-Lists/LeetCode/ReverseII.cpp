/**
 * Question -> https://leetcode.com/problems/reverse-linked-list-ii/
 * 
 * Given the head of a singly linked list and two integers left and right where left <= right,
 * reverse the nodes of the list from position left to position right, and return the reversed list.
 * 
 * Example 1:
 *     Input: head = [1,2,3,4,5], left = 2, right = 4
 *     Output: [1,4,3,2,5]
 * Example 2:
 *     Input: head = [5], left = 1, right = 1
 *     Output: [5]
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
    
    // Below solution is from the posts -> 
    // > https://leetcode.com/problems/reverse-linked-list-ii/discuss/30666/Simple-Java-solution-with-clear-explanation
    // > https://leetcode.com/problems/reverse-linked-list-ii/discuss/30709/Talk-is-cheap-show-me-the-code-(and-DRAWING)                                     
    ListNode* reverseBetween(ListNode *head, int left, int right){

        // the node before the start of the linked list region to reverse
        ListNode *preNode = new ListNode(0, head);
        
        // go to the node before the start of the region of head node to reverse
        for(int i=0; i<left-1; i++){
            preNode = preNode->next;
        }
        
        ListNode *tail = preNode->next; // start of reverse region linked list will become tail
        
        for(int i=0; i<right-left; i++){
            ListNode *temp = preNode->next;
            preNode->next = tail->next;
            tail->next = tail->next->next;
            preNode->next->next = temp;        
        }

        // if the head node is the start of the reverse region of linked list then 
        // the pointer to head after reversing should change. Else the pointer to the head
        // node remains the same.
        if(left ==1) head = preNode->next; 
        
        return head;
    }
    
    //Intuition -> we start iterating over the nodes from start to left-1
    // and we reverse till the right and store next node of right node
//     ListNode* reverseBetween(ListNode* head, int left, int right) {
        
           // start walking from start to left-1 position
//         int cnt = 1;
//         ListNode *walker = head;
//         while(cnt<left-1 && walker!=NULL){
//             walker = walker->next;
//             cnt++;
//         }
        
           // this is the node before the left position node
//         ListNode *headNode = walker;
        
//         ListNode *startNode; // the start node of the linked list portion to reverse
//         ListNode *endNode; // the end node of the linked list portion to reverse
        
//         // Normal reverse operation
//         ListNode *back = NULL; 
//         ListNode *fwd; 
//         if(walker!=NULL && walker->next!=NULL){
                // if we need to reverse from first node then
                // fwd and startNode is walker
//             if(left == 1){
//                 fwd = walker;
//                 startNode = walker;
//             }
               // else we need to go to the next node of fwd node
//             else{
//                 fwd = walker->next;
//                 startNode = walker->next;
//                 cnt++; // entered in the zone of linked list to reverse
//             }
//         }
//         // left>n then return
//         else{
//             return head;
//         }
        
           // reverse nodes from left to right pos
//         while(cnt<=right && fwd!=NULL){
//             ListNode *nextNode = fwd->next;
//             fwd->next = back;
//             back = fwd;
//             fwd = nextNode;
//             cnt++;
//         }


            // make tail point to the next node to the right
//         startNode->next = fwd;
//         if(left == 1){
//             head = back;
//             return head;
//         }
            // make head point to the new head of the linked list region
//         headNode->next = back;
                
//         return head;
//     }
};