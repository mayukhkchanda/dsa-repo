/**
 * Question: https://www.geeksforgeeks.org/detect-and-remove-loop-in-a-linked-list/
 * Practise: https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/1
 * 
 * 
 * Given a linked list of N nodes such that it may contain a loop.
 * 
 * A loop here means that the last node of the link list is connected to the node at position X.
 * If the link list does not have any loop, X=0. Remove the loop from the linked list, if it is present.  
 * 
 * Example 1:
 *     Input:
 *     N = 3
 *     value[] = {1,3,4}
 *     X = 2
 *     Output: 1
 *     Explanation: The link list looks like
 *     1 -> 3 -> 4
 *         ^    |
 *         |____|    
 *     A loop is present. If you remove it 
 *     successfully, the answer will be 1. 
 * 
 * Example 2:
 *     Input:
 *     N = 4
 *     value[] = {1,8,3,4}
 *     X = 0
 *     Output: 1
 *     Explanation: The Linked list does not 
 *     contains any loop. 
 * 
 * Example 3:
 *     Input:
 *     N = 4
 *     value[] = {1,2,3,4}
 *     X = 1
 *     Output: 1
 *     Explanation: The link list looks like 
 *     1 -> 2 -> 3 -> 4
 *     |______________|
 *     A loop is present. 
 *     If you remove it successfully, 
 *     the answer will be 1. 
 * 
 * Your Task:
 * You don't need to read input or print anything. Your task is to complete the function removeLoop() which takes the head of the linked list as the input parameter. Simply remove the loop in the list (if present) without disconnecting any nodes from the list.
 * Note: The generated output will be 1 if your submitted code is correct.
 * 
 * Main Idea:
 *  > Use Cycle detection to find if there's a cycle and find the start node of the cycle if it
 *      exists. Then from the starting point of the loop keep walking until we reach the node before
 *      the start node of the linked lists. Then set it's next node to null.
 * 
 * */


/*
structure of linked list node:

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to remove a loop in the linked list.
    void removeLoop(Node* head)
    {
        Node *slow = head;
        Node *fast = head;
        
        bool hasLoop = false;
        
        while(fast != NULL and fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast){
                hasLoop = true;
                break;
            }
        }
        
        if(!hasLoop){
            return;
        }
        
        Node *finder = head;
        while(slow != finder){
            slow = slow->next;
            finder = finder->next;
        }
        
        Node *tail = finder; 
        
        while( tail->next != finder){
            tail = tail->next;
        }
        
        tail->next = NULL;
        
        return ;
    }
};