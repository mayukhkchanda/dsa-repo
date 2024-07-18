/**
 * Question: https://leetcode.com/problems/swap-nodes-in-pairs/
 * 
 * Given a linked list, swap every two adjacent nodes and return its head.
 * You must solve the problem without modifying the values in the list's 
 * nodes (i.e., only nodes themselves may be changed.)
 * 
 * Example 1:
 *     Input: head = [1,2,3,4]
 *     Output: [2,1,4,3]
 * Example 2:
 *     Input: head = []
 *     Output: []
 * Example 3:
 *     Input: head = [1]
 *     Output: [1]
 * 
 * Solution#1 Discussion with pictures comment for the:
 *  > https://leetcode.com/problems/swap-nodes-in-pairs/discuss/11046/My-simple-JAVA-solution-for-share/186959
 * 
 * Simulation:
 *   DummyHead -> 1 -> 2 -> 3 -> 4 -> 5 -> NULL
 *      ^         ^    ^    ^
 *      |         |    |    +--- next_node   
 *    tail     first  second
 *      
 *      1. tail->next = second;
 * 
 *                   +-----------+
 *                   |           |
 *              DummyHead   1 -> 2 -> 3 -> 4 -> 5 -> NULL
 *                   ^       ^    ^    ^
 *                   |       |    |    +--- next_node   
 *                 tail   first  second
 *          
 * 
 * 
 *      2. second->next = first;
 * 
 *                   +-----------+
 *                   |           |
 *              DummyHead   1 <- 2 -> 3 -> 4 -> 5 -> NULL
 *                   ^      ^    ^    ^
 *                   |      |    |    +--- next_node   
 *                 tail  first  second
 *          
 * 
 *      3. first->next = next_node;
 * 
 *                          +---------+
 *                   +------|----+    |
 *                   |      |    |    |
 *              DummyHead   1 <- 2 -> 3 -> 4 -> 5 -> NULL
 *                   ^      ^    ^    ^
 *                   |      |    |    +--- next_node   
 *                 tail  first  second
 * 
 * 
 *        Final representation:
 *      
 *              DummyHead -> 2 -> 1 -> 3 -> 4 -> 5 -> NULL
 *                   ^       ^    ^    ^
 *                   |       |    |    +--- next_node   
 *                 tail   first  second
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

    // solution #1
    ListNode* swapPairs(ListNode* head) {
        
        ListNode *dummyHead = new ListNode(-1, head);
        ListNode *tail = dummyHead;
        
        while(tail->next != NULL and tail->next->next!=NULL){
            
            // simulation above
            ListNode *first = tail->next;
            ListNode *second = tail->next->next;
            
            ListNode *next_node = second->next;
            
            tail->next = second;
            second->next = first;
            first->next = next_node;
            
            tail = first;
            
        }
        
        return dummyHead->next;       
    }
    

    // Solution#2 below uses the approach behind reverse k nodes problems,where k is 2 in this case.
//     ListNode* reverse(ListNode *start, ListNode *end){
        
//         ListNode *tail = start->next;
        
//         ListNode *fwd = start->next;
//         ListNode *back = NULL;
        
//         while(fwd != NULL && fwd != end){
//             ListNode *next_node = fwd->next;
//             fwd->next = back;
//             back = fwd;
//             fwd = next_node;
//         }
        
//         start->next = back;
//         tail->next = fwd;
        
//         return tail;    
//     }
    
// public:
//     ListNode* swapPairs(ListNode* head) {
//         ListNode *dummyHead = new ListNode(-1, head);
//         ListNode *begin = dummyHead;
        
//         int k = 2; // number of nodes to reverse at a time
        
//         int cnt = 0;
        
//         while(head!=NULL){
            
//             cnt++;
//             if(cnt%k == 0){
//                 begin = reverse(begin, head->next);
//                 head = begin;
//             }
            
//             head = head->next;
//         }
        
//         return dummyHead->next;
//     }
};