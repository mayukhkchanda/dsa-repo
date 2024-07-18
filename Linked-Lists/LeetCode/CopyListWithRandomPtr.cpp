/**
 * Question: https://leetcode.com/problems/copy-list-with-random-pointer/
 * A linked list of length n is given such that each node contains an additional random pointer,
 * which could point to any node in the list, or null.
 * 
 * Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes,
 * where each new node has its value set to the value of its corresponding original node. Both 
 * the next and random pointer of the new nodes should point to new nodes in the copied list such 
 * that the pointers in the original list and copied list represent the same list state. None of
 * the pointers in the new list should point to nodes in the original list.
 * 
 * For example, if there are two nodes X and Y in the original list, where X.random --> Y, then 
 * for the corresponding two nodes x and y in the copied list, x.random --> y.
 * 
 * Return the head of the copied linked list.
 * 
 * Example 1:
 *   Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
 *   Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]
 * Example 2:
 *   Input: head = [[1,1],[2,1]]
 *   Output: [[1,1],[2,1]]
 * Example 3:
 *   Input: head = [[3,null],[3,0],[3,null]]
 *   Output: [[3,null],[3,0],[3,null]]
 * Example 4:
 *   Input: head = []
 *   Output: []
 *   Explanation: The given linked list is empty (null pointer), so return null.
 * 
 * Solution Discussion:
 *  > https://leetcode.com/problems/copy-list-with-random-pointer/discuss/43497/2-clean-C%2B%2B-algorithms-without-using-extra-arrayhash-table.-Algorithms-are-explained-step-by-step.
 *  > Pictorial Explanation: https://leetcode.com/problems/copy-list-with-random-pointer/discuss/43497/2-clean-C++-algorithms-without-using-extra-arrayhash-table.-Algorithms-are-explained-step-by-step./349221
 * 
 * Simulation of the Code:
 *  1. Make a copy of all the nodes and assign them to the next node of the orginal node.
 *      Keep their random pointers blank for now.
 *  2. Now build the connection of the new nodes to the random pointer using the original nodes.
 *  3. Seperate the original and new nodes.
 * 
 * */


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
    
public:
    Node* copyRandomList(Node* head) {
        Node *dummyHead = new Node(-1);
        dummyHead->next = head;
        
        //create new nodes and join them to the next node of the original nodes
        while(head != NULL){
            Node *next_node = head->next;
            
            Node *new_node = new Node(head->val);
            new_node->next = head->next;
            head->next = new_node;
            
            head = new_node->next;
        }
        
        
        //assign the random pointers
        head = dummyHead->next;
        
        while(head!=NULL){
            Node *new_node = head->next;
            new_node->random = head->random != NULL ? head->random->next : NULL;
            head = head->next->next;
        }
        
        Node *new_head = new Node(-1);
        Node *tail = new_head;
        
        head = dummyHead->next;
        
        //extract the new nodes
        while(head!=NULL){
            tail->next = head->next;
            tail = tail->next;
            
            head->next = head->next->next;
            head = head->next;
        }        
        
        // set the next of end node to NULL
        tail->next = NULL;
        
        head = dummyHead->next;
        return new_head->next;        
    }
};