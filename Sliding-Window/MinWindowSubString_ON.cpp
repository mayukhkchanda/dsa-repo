#include <iostream>
#include <cstring>
#include <climits>
using namespace std;


/**
 * Question:: https://leetcode.com/problems/minimum-window-substring/
 * 
 * Same as SmallestWindowOfUniqueCharsOfStr_ON.cpp question. 
 * Solved using the template given here::
 *  https://leetcode.com/problems/minimum-window-substring/discuss/26808/Here-is-a-10-line-template-that-can-solve-most-'substring'-problems
 */

string minWindow(string str, string word) {
    
    int strFrqMap[256] = {0};
    int wordFrqMap[256] = {0};
    
    // calculate the char-freq of word
    for (int i = 0; i < word.size(); i++) {
        wordFrqMap[word[i]]++;
    }
    
    int len_word = word.size();
    
    // count of characters matched
    int counter=0;
    
    // current window start and end index
    int start = 0;
    int end = 0;
    
    // minimum window len and it's start index 
    int min_window_len   = INT_MAX;
    int min_window_start = -1;
    
    while(end<str.size()){
        
        // increase the frq of this character in str's frequency map
        strFrqMap[str[end]]++;
        
        // if this character exists in word and it's count is less than or equal to 
        // the count in word then increment the counter
        if(strFrqMap[str[end]]<=wordFrqMap[str[end]]){
            counter++;
        }
        
        // if all characters are matched then this is a valid window
        while(counter == len_word){
            
            // if the window length is smaller than the current min_window replace it
            if(end-start+1 < min_window_len){
                min_window_len = end-start+1;
                min_window_start = start;
            }
                
            // when a valid window is found, try to shrink it 
            strFrqMap[str[start]]--;
            
            // if the character removed exists in word and it's frequency has become less than that of word 
            // then decrement the counter
            if(wordFrqMap[str[start]]>0 && strFrqMap[str[start]]<wordFrqMap[str[start]]){
                counter--;
            }
            
            // increment start
            start++;
        }
        
        end++;
    }
    
    if(min_window_start != -1) return str.substr(min_window_start, min_window_len);
    
    return "";
}

int main() {
	
	string s ;//= "cbaebabacd";
	string t ;//= "abc";
	
	getline(cin, s);
	getline(cin, t);
	
	cout<< minWindow(s,t)<<"\n";
	
	return 0;
}