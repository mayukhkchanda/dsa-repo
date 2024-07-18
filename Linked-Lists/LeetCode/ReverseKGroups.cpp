/**
 * Question -> https://leetcode.com/problems/reverse-nodes-in-k-group/
 * 
 * Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
 * 
 * k is a positive integer and is less than or equal to the length of the linked list. If the number 
 * of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.
 * You may not alter the values in the list's nodes, only nodes themselves may be changed.
 * 
 * Example 1:
 *     Input: head = [1,2,3,4,5], k = 2
 *     Output: [2,1,4,3,5]
 * Example 2:
 *     Input: head = [1,2,3,4,5], k = 3
 *     Output: [3,2,1,4,5]
 * Example 3:
 *     Input: head = [1,2,3,4,5], k = 1
 *     Output: [1,2,3,4,5]
 * Example 4:
 *     Input: head = [1], k = 1
 *     Output: [1]
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
    
    // reverse nodes between begin and end nodes(both exclusive)
    ListNode* reverse(ListNode *begin, ListNode* end){ 
        // after reversing the beginining of the linked list region will become the tail
        ListNode *tail = begin->next;
        
        // reverse the nodes
        ListNode *fwd = begin->next;
        ListNode *back = begin;
        
        while(fwd != end){
            ListNode *nextNode = fwd->next;
            fwd->next = back;
            back = fwd;
            fwd = nextNode;
        }
        
        //after reversing back becomes the head of this region, hence connect it with the
        //region before this
        begin->next = back; 
        
        //connect the tail to the next region starting from end
        tail->next = end;
        
        // return tail of the node that will become the new begining for the next section
        // of the linked list
        return tail;        
    }
    
    
    public: 
        // below solution is from the post ->
        // > https://leetcode.com/problems/reverse-nodes-in-k-group/discuss/11440/Non-recursive-Java-solution-and-idea
        ListNode* reverseKGroup(ListNode* head, int k) {
                
            ListNode *dummyHead = new ListNode(0, head);
            ListNode *begin = dummyHead;
            
            int cntNodes = 0;
            
            while(head != NULL){
                
                cntNodes++;
                //if # of nodes is a multiple of k then nodes from begin to next of
                //current node both exclusive should be reversed
                if(cntNodes%k == 0){
                    begin = reverse(begin, head->next);
                    head = begin;
                }
                head = head->next;
            }
            
            return dummyHead->next;
        }
    
    
    
    
    
    
    
    
    
//     ListNode* reverse(ListNode *head, ListNode *stopAtNode){
        
//         ListNode *fwd = head;
//         ListNode *back = NULL;

//         // reverse nodes from head node to the node before stopAtNode
//         while(fwd != stopAtNode){
//             ListNode *next = fwd->next;
//             fwd->next = back;
//             back = fwd;
//             fwd = next;        
//         }
        
//         // return new head of this linked list
//         return back;
//     }
    
// public: //time complexity is o(2N)
//     ListNode* reverseKGroup(ListNode* head, int k) {
        
//         ListNode *pre = new ListNode(0);
//         pre->next = head;
        
//         // ListNode *start = new ListNode(0, head);
//         ListNode *walker = head;
        
//         int cntNodes = 0;
        
//         while(walker != NULL){
//             cntNodes++;
            
//             // reversed only if there are k-nodes before this node
//             if(cntNodes%k == 0){
                
//                 //1.store the next node to go i.e. the (m*k+1)th node [m is any +ve integer]
//                 ListNode *next = walker->next;
                
//                 //2. store the next node of pre node as tail since this will be reversed
//                 ListNode *tail = pre->next;
                
//                 //3.reverse linked list region from next node of pre node to the node before
//                 //the next node and get the new head
//                 ListNode *reversedHead = reverse(pre, walker->next);
                
//                 //4. connect the tail with the remaining nodes
//                 tail->next = next; 
                
//                 //5.set new head if first k nodes are reversed
//                 if(cntNodes/k == 1){
//                     head = reversedHead;
//                 }
//                 //else connect the new head with the next of pre node
//                 else{
//                     pre->next = reversedHead;
//                 }
                
//                 //6.shift pre and walker to kth node after reversing as the nodes are reversed and
//                 //tail is the end of this k-linked lists region that is connect to remaining nodes
//                 pre = walker = tail;
//             }
            
//             walker = walker->next;
//         }
//         return head;
//     }


};