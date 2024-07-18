/**
 * Question: https://leetcode.com/problems/reverse-words-in-a-string-iii/
 * 
 * Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.
 * 
 * Example 1:
 *     Input: s = "Let's take LeetCode contest"
 *     Output: "s'teL ekat edoCteeL tsetnoc"
 * Example 2:
 *     Input: s = "God Ding"
 *     Output: "doG gniD"
 * 
 * */

class Solution {
    
    void reverse(string &str, int start, int end){
        
        while(start < end){
            swap(str[start], str[end]);
            start++;
            end--;
        }
        
    }
    
public:
    string reverseWords(string s) {
        
        int n=s.length();
        
        for(int i=0; i<n; i++){
            
            int j = i;
            while( j<n && s[j] != ' '){
                j++;
            }
            
            reverse(s, i, j-1);
            i=j;
        }
        return s;
    }
};