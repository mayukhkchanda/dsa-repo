#include <iostream>
#include <string>
#include <cstring>
using namespace std;

/**
 * 
 * Question: https://leetcode.com/problems/break-a-palindrome/
 * Given a palindromic string of lowercase English letters palindrome, replace exactly one character
 * with any lowercase English letter so that the resulting string is not a palindrome and that it is 
 * the lexicographically smallest one possible.Return the resulting string. If there is no way to replace
 * a character to make it not a palindrome, return an empty string.
 
 * A string a is lexicographically smaller than a string b (of the same length) if in the first position where a and b differ, 
 * a has a character strictly smaller than the corresponding character in b. For example, "abcc" is lexicographically smaller 
 * than "abcd" because the first position they differ is at the fourth character, and 'c' is smaller than 'd'.

 * Example 1:
 * Input: palindrome = "abccba"
 * Output: "aaccba"
 * Explanation: There are many ways to make "abccba" not a palindrome, such as "zbccba", "aaccba", and "abacba".
 * Of all the ways, "aaccba" is the lexicographically smallest
 
 * Approach::
 * The palindrome string will have same characters at same place from 2 ends.
 * If a character equals 'a' then, we cannot replace it with any other character
 * to make it lexiographically smaller. Thus we check every character till the middle(due to symetry of palindrome we dont need to check for the other end)
 * for some character at index i such that str[i] != 'a'(if we find one) we can change it to 'a'. If all characters are 'a', then
 * we change the very last character to 'b'.
 * 
 * CASE I: palindrome = aaabaaa OR aaaaa -> since all character are 'a' and changing the middle character would not
 *          do anything, so we change last character to 'b' to make it lexiographically smallest.
 *                         ---
 * CASE II: palindrome = aa|b|baa -> we cannot replace 'a' with any character to make it smaller. So we change 'b'
 *                         ---
 *          enclosed in boxes to 'a' to make it lexiographically smallest and break the palindrome.
 * 
 * Any other given input string will fall in this 2 category only.
 * 
 * Time Complexity:: While loop runs til i reaches n/2 so the function is bounded by O(N)
 * 
 * */
string breakPalindrome(string palindrome) {
    
    int n= palindrome.size()-1; //last index
    
    int i=0;
    
    while(i<n-i){ //we don't care about the middle index when n is odd
        
        if(palindrome[i] != 'a'){
            palindrome[i] = 'a';
            
            return palindrome;
        }
        i++;
    }
    
    //else all characters are 'a' or  all characters are 'a' except the middle character.
    //Only changing the last character to 'b' is the only option
    
    palindrome[n] = 'b';
    
    return palindrome;
}

int main() {
	
// 	string str = "abccba";
// 	string str = "aabaa";
// 	string str = "aaaaa";
	string str = "aabbaa";
	
	cout<<breakPalindrome(str);
	
	return 0;
}
