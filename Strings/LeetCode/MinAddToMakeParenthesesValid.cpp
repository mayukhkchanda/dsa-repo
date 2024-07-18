/**
 * Question: https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/
 * 
 * A parentheses string is valid if and only if:
 * It is the empty string,
 * It can be written as AB (A concatenated with B), where A and B are valid strings, or
 * It can be written as (A), where A is a valid string.
 * You are given a parentheses string s. In one move, you can insert a parenthesis 
 * at any position of the string.
 * For example, if s = "()))", you can insert an opening parenthesis to be "(()))" or a
 * closing parenthesis to be "())))". Return the minimum number of moves required to make s valid.
 * 
 * Example 1:
 *     Input: s = "())"
 *     Output: 1
 * Example 2:
 *     Input: s = "((("
 *     Output: 3
 * Example 3:
 *     Input: s = "()"
 *     Output: 0
 * Example 4:
 *     Input: s = "()))(("
 *     Output: 4
 * 
 * Solution Discussion:
 *  > https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/discuss/181086/JavaPython-3-two-one-pass-codes-space-O(n)-and-O(1)-respectively
 * 
 * */

class Solution {
public:
    int minAddToMakeValid(string str) {

        int n = str.length();
        
        int open = 0;
        int req = 0;
        
        for(int i=0; i<n; i++){
            
            if(str[i] == '('){ // open brace 
                open++;                
            }
            else{ //str[i] = ')' // close brace
                
                // if there's an open brace before this, then it will paired
                if(open > 0){
                    open--;
                }
                // else we need an open brace to pair this
                else{
                    req++;
                } 
            }
        }
        
        // if there's open braces that have not been paired then
        // we need same # of closing braces too
        req += open;
        
        
        return req;
    
    }
};