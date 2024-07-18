/**
 * Question -> https://leetcode.com/problems/add-two-numbers-ii/
 * 
 * You are given two non-empty linked lists representing two non-negative integers.
 * The most significant digit comes first and each of their nodes contains a single
 * digit. Add the two numbers and return the sum as a linked list.
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 * Example 1:
 *   Input: l1 = [7,2,4,3], l2 = [5,6,4]
 *   Output: [7,8,0,7]
 * Example 2:
 *   Input: l1 = [2,4,3], l2 = [5,6,4]
 *   Output: [8,0,7]
 * Example 3:
 *   Input: l1 = [0], l2 = [0]
 *   Output: [0]
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
    
    int size(ListNode *head){
        int len = 0;
        while(head!=NULL){
            head = head->next;
            len++;
        }
        return len;
    }
    
    void insertAtHead(ListNode * &head, int num){
        
        ListNode *new_node = new ListNode(num);
        new_node->next = head->next;
        head->next = new_node;      
    }
    
    void normalise(ListNode *head){
        ListNode *tail = NULL;
        
        int sum = 0;
        int carry = 0;
        
        while(head != NULL){
            
            // normalising the value
            int num = head->val;
            sum = num+carry;
            carry = sum/10;
            head->val = sum%10;
            
            tail = head;
            head = head->next;
        }
        
        if(carry > 0){
            tail->next = new ListNode(carry);
        }
        
    }
    
    void reverse(ListNode * &head){
        ListNode *tail = NULL;
        
        while(head != NULL){
            ListNode *next_node = head->next;
            head->next = tail;
            tail = head;
            head = next_node;
        }
        
        head = tail;
    }
    
     public:
        // Below solution is based on the post
        //   > https://leetcode.com/problems/add-two-numbers-ii/discuss/687339/Java-O(N)-solution-with-follow-up-question-no-recursion-no-stacks
        ListNode* addTwoNumbers(ListNode* head1, ListNode* head2) {
            
            int len1 = size(head1);
            int len2 = size(head2);
            
            ListNode *result = new ListNode(-1);
            ListNode *tail = result;
            
            while(head1 != NULL  && head2 != NULL){
                
                int num1 = 0;
                int num2 = 0;
                
                if(len1 > len2){
                    num1 = head1->val;
                    num2 = 0;
                    len1--;
                    head1 = head1->next;
                }else if(len2 > len1){
                    num1 = 0;
                    num2 = head2->val;
                    len2--;
                    head2 = head2->next;                    
                }else{
                    num1 = head1->val;
                    num2 = head2->val;
                    len1--;
                    len2--;
                    head1 = head1->next;
                    head2 = head2->next;
                }
                
                int sum = num1 + num2;
                
                insertAtHead(tail, sum);
            }
            
            // normalise and add the carrys
            normalise(result->next);
            
            // reverse the list
            reverse(result->next);
            
            return result->next;
        }
    
    
    /** below code reverses the linked lists **/
//     void reverse(ListNode * &head){
//         ListNode *tail = NULL;
        
//         while(head != NULL){
//             ListNode *next_node = head->next;
//             head->next = tail;
//             tail = head;
//             head = next_node;
//         }
        
//         head = tail;
//     }
    
//     ListNode* add(ListNode* head1, ListNode* head2){
//         ListNode *result = new ListNode(-1);
//         ListNode *tail = result;
        
//         int sum = 0;
//         int carry = 0;
        
//         while(head1 != NULL || head2 != NULL){
//             int num1 = head1 != NULL ? head1->val : 0;
//             int num2 = head2 != NULL ? head2->val : 0;
            
//             sum = num1 + num2 + carry;
//             carry = sum/10;
            
//             tail->next = new ListNode(sum%10);
//             tail = tail->next;
            
//             head1 = head1 != NULL ? head1->next : NULL;
//             head2 = head2 != NULL ? head2->next : NULL;        
//         }
        
//         if(carry > 0){
//             tail->next = new ListNode(carry);
//             tail = tail->next;
//         }
        
//         return result->next;
//     }
    
// public:
//     ListNode* addTwoNumbers(ListNode* head1, ListNode* head2) {
//         reverse(head1);
//         reverse(head2);
        
//         ListNode *result = add(head1, head2);
        
//         reverse(result);
        
//         return result;
        
//     }
};





