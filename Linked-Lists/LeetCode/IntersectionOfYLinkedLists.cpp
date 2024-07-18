/**
 * Question: https://leetcode.com/problems/intersection-of-two-linked-lists
 * 
 * Given the heads of two singly linked-lists headA and headB, return the node at which the two
 *  lists intersect. If the two linked lists have no intersection at all, return null.
 * 
 * The test cases are generated such that there are no cycles anywhere in the entire linked structure.
 * Note that the linked lists must retain their original structure after the function returns.
 * 
 * intersectVal - The value of the node where the intersection occurs. This is 0 if there is no intersected node.
 * listA - The first linked list.
 * listB - The second linked list.
 * skipA - The number of nodes to skip ahead in listA (starting from the head) to get to the intersected node.
 * skipB - The number of nodes to skip ahead in listB (starting from the head) to get to the intersected node.
 * The judge will then create the linked structure based on these inputs and pass the two heads, headA and headB to your program. If you correctly return the intersected node, then your solution will be accepted.
 * 
 * Example 1:
 *     Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3
 *     Output: Intersected at '8'
 *     Explanation: The intersected node's value is 8 (note that this must not be 0 if the two lists 
 *     intersect). From the head of A, it reads as [4,1,8,4,5]. From the head of B, it reads as 
 *     [5,6,1,8,4,5]. There are 2 nodes before the intersected node in A; There are 3 nodes before the 
 *     intersected node in B.
 * Example 2:
 *     Input: intersectVal = 2, listA = [1,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
 *     Output: Intersected at '2'
 *     Explanation: The intersected node's value is 2 (note that this must not be 0 if the two lists
 *     intersect). From the head of A, it reads as [1,9,1,2,4]. From the head of B, it reads as [3,2,4].
 *     There are 3 nodes before the intersected node in A; There are 1 node before the intersected node
 *     in B.
 * Example 3:
 *     Input: intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
 *     Output: No intersection
 *     Explanation: From the head of A, it reads as [2,6,4]. From the head of B, it reads as [1,5].
 *     Since the two lists do not intersect, intersectVal must be 0, while skipA and skipB can be 
 *     arbitrary values.
 *     Explanation: The two lists do not intersect, so return null.
 * 
 * Solution Discussion:
 *  > Without knowing the length of the lists-
 *      > Post: https://leetcode.com/problems/intersection-of-two-linked-lists/discuss/49785/Java-solution-without-knowing-the-difference-in-len!
 *      > Visualization: https://leetcode.com/problems/intersection-of-two-linked-lists/discuss/49785/Java-solution-without-knowing-the-difference-in-len!/165648
 *    
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
        // The main aim here is to counter the difference in length of both of 
        // the lists. Iterate over each of the linked lists till we reach a same 
        // node or either one of them reaches the end. If the length are different
        // then one of them will reach the end quicker than the other. When that
        // happens we make the pointer to the head of the other linked list. As the 
        // lengths are different thus after reaching the head of the other node it 
        // will cover the difference in the length of the two linked list. After it 
        // has cover the difference in the length the other linked list will also
        // point to the end and will be reset to the other linked list's head. Hence
        // both reach the same length from the end and we can iterate over them until
        // they reach a common node or null node(in case of no intersection)
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        ListNode *headA_cache = headA;
        ListNode *headB_cache = headB;
        
        while(headA != headB){
            headA = headA!=NULL ? headA->next : headB_cache;
            headB = headB!=NULL ? headB->next : headA_cache;
        }
        
        return headA;
    }
    
    
    //Below solution uses length of two linked lists to solve the problem
//     int size(ListNode *head){
//         int len = 0;
//         while(head!=NULL){
//             len++;
//             head = head->next;
//         }
//         return len;
//     }
    
// public:
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
            // get the length of both linked list
//         int lenA = size(headA);
//         int lenB = size(headB);
        
            // iterate over the linked lists untill either of them reaches the end
            // which would mean no intersection or we get an intersection
//         while( headA!=NULL && headB!=NULL ){
                
                // if we get an intersection then we can return as it will be the first
                // intersection
//             if(headA == headB){
//                 return headA;
//             }
            
                // Move the linked list of the larger linked list untill both
                // have the same size. Once they have the same size then we can
                // move them together untill they meet at a node or we reach the 
                // end of the lists.
//             if(lenA > lenB){
//                 headA = headA->next;
//                 lenA--;
//             }else if(lenB > lenA){
//                 headB = headB->next;
//                 lenB--;
//             }else{
//                 headA = headA->next;
//                 headB = headB->next;
//                 lenA--;
//                 lenB--;
//             }
            
//         }
        
        
//         return NULL;
//     }
};