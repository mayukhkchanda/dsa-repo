#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

/** Question:: https://leetcode.com/problems/find-all-anagrams-in-a-string/
 * Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.
 * Example 1:
 *  Input: s = "cbaebabacd", p = "abc"
 *  Output: [0,6]
 *  Explanation:
 *  The substring with start index = 0 is "cba", which is an anagram of "abc".
 *  The substring with start index = 6 is "bac", which is an anagram of "abc".
 *  
 *  Links below provide a template for solving sliding window problems that apply to most of the problems::
 *  Good template, tricky Explanation:: 
 *      https://leetcode.com/problems/find-all-anagrams-in-a-string/discuss/92007/Sliding-Window-algorithm-template-to-solve-all-the-Leetcode-substring-search-problem.
 *  
 *  Good template, great Explanation::
 *      https://leetcode.com/problems/minimum-window-substring/discuss/26808/Here-is-a-10-line-template-that-can-solve-most-'substring'-problems
 *      see 1st comment too:: https://leetcode.com/problems/minimum-window-substring/discuss/26808/Here-is-a-10-line-template-that-can-solve-most-'substring'-problems/25861.
 * 
 * 
 * Approach::
 *  > Intialize a character map for storing frequency of characters. 
 *  > Have a counter variable to keep count of the number of characters matched so far between string and word.
 *  > Start iterating over str and keep start and end for marking start and end of the current window.
 *  > When a character in str exists in word and its frequency till the current index(inside of a loop) is less
 *      than frequency of same character in word, then increase the counter.
 *  > when the counter becomes equal to the length of the word, then we found a valid window.
 *  > we start contracting the window, until the counter falls below the length of word.
 *  > while contracting we check to see if the window len == the length of word as we want the same characters and
 *      their exact frequency for an anagram. If such an window is found we store it's starting index
 * */


 vector<int> findAnagrams(string str, string word){

    //store the character-frequency 
    int charMapWord[27] ={0};
    int charMapStr[27] ={0};
        
    for (int i = 0; i < word.size(); i++) {
        charMapWord[word[i]-'a']++;
    }
    
    int len_word = word.size();
    
    // stores the count of characters matched
    int counter =0 ;
    
    int start=0; // window start index
    int end=0;   // window end index
    
    vector<int> startIndices;
    
    while(end < str.size()){
        
        charMapStr[str[end]-'a']++;
        
        // if this character exists in word and it's frequency in str is less than or equal
        // to # of characters in word
        if(charMapStr[str[end]-'a'] <= charMapWord[str[end]-'a'])
            counter++;
        
        //until counter falls below length of word
        while(counter == len_word){
            
            // decrease the frequency of character(str[start]) in the character-frequency map of str 
            charMapStr[str[start]-'a']--;
            
            //if this window had exactlly the same number of characters as word then
            //add this window's start to the result
            if(end-start+1 == len_word){
                startIndices.push_back(start);
            }
            
            //if this character existed in word and it's count in str became less than count in word
            //due to contracting the window, then decrease the counter
            if( charMapWord[str[start]-'a']>0  &&  charMapStr[str[start]-'a'] < charMapWord[str[start]-'a'] ){
                counter--;
            }
            
            //finally contract the window
            start++;
        }
        end++;
    }
    
    return startIndices;
}

int main() {
	
	string s ;//= "cbaebabacd";
	string t ;//= "abc";
	
	getline(cin, s);
	getline(cin, t);
	
	vector<int> allStartIndexes = findAnagrams(s,t);
	
	for (auto i : allStartIndexes) {
    	cout<< i<<" ";
	}
	
	return 0;
}
