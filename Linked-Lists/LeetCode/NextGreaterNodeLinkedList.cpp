/**
 * Question: https://leetcode.com/problems/next-greater-node-in-linked-list/
 * 
 * You are given the head of a linked list with n nodes.
 * 
 * For each node in the list, find the value of the next greater node. That is, 
 * for each node, find the value of the first node that is next to it and has a 
 * strictly larger value than it.
 * 
 * Return an integer array answer where answer[i] is the value of the next greater 
 * node of the ith node (1-indexed). If the ith node does not have a next greater 
 * node, set answer[i] = 0.
 * 
 * Example 1:
 *     Input: head = [2,1,5]
 *     Output: [5,5,0]
 * Example 2:
 *     Input: head = [2,7,4,3,5]
 *     Output: [7,0,5,5,0]
 * 
 * Solution Discussion:
 *  > https://leetcode.com/problems/next-greater-node-in-linked-list/discuss/265548/C%2B%2B-O(n)-stack
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
    vector<int> nextLargerNodes(ListNode* head) {
        
        // we use a stack as a monotonic decreasing stack keeping pair of node_value
        // and index. Whenever we pop off from this stack, we use the index to assign
        // the next greater value to this index.
        stack<pair<int, int>> stk; // {node_val, index}
        vector<int> nextGreater;
        
        int len = 0;
        
        while(head!=NULL){
            
            // pop off elements from the stack when a larger values comes
            while(!stk.empty() && stk.top().first < head->val){
                // assign the next greater element for this index
                nextGreater[stk.top().second] = head->val;
                stk.pop();
            }
            
            // push the current value and index
            stk.push({head->val, len});
            // move the head node
            head = head->next;
            // as we haven't found the next greater element for this index yet, 
            // so we push back 0
            nextGreater.push_back(0);
            len++;
        }
        
        return nextGreater;
    }
};