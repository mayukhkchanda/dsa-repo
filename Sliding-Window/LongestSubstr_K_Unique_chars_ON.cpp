#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;


/**
 * Question:: https://www.geeksforgeeks.org/find-the-longest-substring-with-k-unique-characters-in-a-given-string/
 * 
 * Given a string you need to print longest possible substring that has exactly M unique characters. 
 * If there are more than one substring of longest possible length, then print any one of them.
 * 
 * Examples: 
 * 
 * "aabbcc", k = 1
 * Max substring can be any one from {"aa" , "bb" , "cc"}.
 * 
 * "aabbcc", k = 2
 * Max substring can be any one from {"aabb" , "bbcc"}.
 * 
 * "aabbcc", k = 3
 * There are substrings with exactly 3 unique characters
 * {"aabbcc" , "abbcc" , "aabbc" , "abbc" }
 * Max is "aabbcc" with length 6.
 * 
 * "aaabbb", k = 3
 * There are only two unique characters, thus show error message. 
 * 
 * Used the template given here:: https://leetcode.com/problems/minimum-window-substring/discuss/26808/Here-is-a-10-line-template-that-can-solve-most-'substring'-problems
 * 
 * Explained Solution:: https://leetcode.com/problems/longest-repeating-character-replacement/discuss/91285/Sliding-window-similar-to-finding-longest-substring-with-k-distinct-characters
 * 
 * Approach:: Used sliding window
 *  > Initialise a character-frequency map.
 *  > Start iterating over the string and keep expanding the window by including characters.
 *  > when a unique character is spotted i.e. it's frequency will be 1 then we increment counter by 1.
 *  > Since exactly k unique characters must be present in the substring so we keep track of when we 
 *    make the window invalid by including extra characters than neccessay.
 *  > When we include more characters than neccessay we start shrinking the window to make it valid again
 *      i.e. unitl counter becomes less than k by incrementing start and removing characters.
 *  > We update the max_window_len after we check for validity of a window and if the counter and k are equal.
 * */


int longestKSubstr(string str, int k) {
    
    // character frequency map for str
    int char_map[256] ={0};
    
    int start = 0; // start index of current window
    int end   = 0; // end index of current window
    
    int max_window_len = -1;
    
    // count of unique characters seen so far
    int counter = 0;
    
    while(end<str.size()){
        
        char_map[str[end]]++;
        
        // if this the first time this character has been seen
        // then increment the counter
        if(char_map[str[end]] == 1){
            counter++;
        }
        
        // if an window became invalid due to inclusion of a character
        // shrink it to make it valid again
        while(counter > k){
            
            // remove a character from start
            char_map[str[start]]--;
            
            // if its frequency became 0 then we lost a unique character
            // hence decrease the counter
            if(char_map[str[start]] == 0){
                counter--;
            }
            
            // finally increment start
            start++;
        }
        
        // if the window is valid only then update the max window/substring length
        if(counter == k){
            max_window_len = max( max_window_len, end-start+1 );
        }
        
        end++;
    }
    
    return max_window_len;
}


int main() {
	string str;
	int k;
	
	getline(cin, str);
	
	cin >> k;
	
	cout<< longestKSubstr(str, k);
	
	return 0;
}
