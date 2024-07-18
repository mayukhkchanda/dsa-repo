/**
 * Question -> https://www.geeksforgeeks.org/nth-node-from-the-end-of-a-linked-list/
 * Implement a function that returns the Kth last of element from the linked list, in a single pass.
 * You can assume K will be less than / equal to length of linked list.
 * 
 * Example: 
 *   Input: 1 -> 2 -> 3 -> 4 -> 5 ->6 ->7, K = 3
 *   Output: 5
 *   Explanation: 3rd last element is 5.
 * 
 * 
 * Solution using 2 pointers and runner technique is discussed below:
 *  > https://www.geeksforgeeks.org/nth-node-from-the-end-of-a-linked-list/
 * 
 * Intuition:
 *  > Initialise two pointers fast and slow(or anything else). Move the fast pointer
 *      to the k-th node from the start. Initialize slow pointer to the first node.
 *      Now move both fast and slow pointers 1 by 1 untill the fast pointer reaches null.
 *      The slow pointer will point to the k-th node from end.
 *  
 *  Simulation:
 *          
 *    head-> 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> NULL 
 *    fast-> ^    ^    ^    ^                              
 *    k =    3    2    1    0
 *          
 *   slow-> |    |    |    |    |
 *   head-> 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> NULL 
 *   fast->                ^    ^    ^    ^     ^ 
 * 
 *  Finally fast->NULL and slow -> 5 ->...->NULL
 */

#include<bits/stdc++.h>
using namespace std;


class node{
public:
	int data;
	node* next;

	node(int data){
		this->data = data;
		next = NULL;
	}
};

int kthLastElement(node *head, int k){
    
    node *fast = head;
    node *slow = head;
    
    while(k && fast != NULL){
        fast = fast->next;
        k--;
    }
    
    while(fast != NULL){
        fast = fast->next;
        slow = slow->next;
    }
    
    return slow->data;
}