#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

/**question:: https://leetcode.com/problems/longest-substring-without-repeating-characters/
 * 
 * Given a string s, find the length of the longest substring without repeating characters.
 * 
 * Example 1:
 *   Input: s = "abcabcbb"
 *   Output: 3
 *   Explanation: The answer is "abc", with the length of 3.
 * 
 *  Nice solution:: https://leetcode.com/problems/longest-substring-without-repeating-characters/discuss/1729/11-line-simple-Java-solution-O(n)-with-explanation
 * 
 * Approach:: Use sliding window
 *  > Have 2 pointers. Expand the window and keep including the character till a repeating character is seen
 *  > At the index of repeating character, start a new subtring.
 *  > Store the max-size substring of them all.
 * 
 * */

int lengthOfLongestSubstring(string str) {
    
    int i=0;// window start
    int j=0;// window end
    
    unordered_map<char, int> charMap;
    
    int max_substr_len = 0;
    int max_substr_start = -1;
    
    while(j<str.size()){
        
        // if this character is present in our current substring
        // we would updated our window start index but only if i < indexof(str.at(j)) i.e. the last indexof of 
        // the repeating character in the substring before the current index
        if(charMap.find(str[j]) != charMap.end()){
            i = max(i, charMap[str[j]]+1);
        }
        
        // now we insert/update the last occurance of this character(either repeating or a new character)
        charMap[str[j]] = j;
        
        // calculate the max substring length
        if(max_substr_len < j-i+1){
            max_substr_len = j-i+1;
            max_substr_start = i;
        }
        
        j++;
    }
    
    cout<<str.substr(max_substr_start, max_substr_len)<<"\n";
    
    return max_substr_len;
}

int main() {
//  	string str = "abcabdced";
    // string str = "a";
    // string str = "";
    // string str="abcabcde";
    // string str="abcde";
    // string str="bbbbb";
    // string str=" abc ";
    // string str=" 123@";
// 	string str="dvdf";
    string str = "abba";
    // string str = "abcabcbb";
    // string str="tmmzuxt";
    // string str=" ";
	
	cout<< lengthOfLongestSubstring(str)<<"\n";
	
	return 0;
}
