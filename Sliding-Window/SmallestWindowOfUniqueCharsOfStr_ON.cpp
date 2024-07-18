#include <iostream>
#include <cstring>
#include <climits>
using namespace std;

/** Given a string 's'. The task is to find the smallest window length that contains all the characters of the given string at least one time.
 * For eg. str = “aabcbcdbca”, then the result would be 4 as of the smallest window will be “dbca” .
 * Examples: 
 *  Input: aabcbcdbca
 *  Output: dbca
 * Explanation: 
 * Possible substrings= {aabcbcd, abcbcd, 
 * bcdbca, dbca....}
 * Of the set of possible substrings 'dbca' 
 * is the shortest substring having all the 
 * distinct characters of given string. 
 *  
 * GFG Question:: https://www.geeksforgeeks.org/smallest-window-contains-characters-string/
 * 
 * Approach::  
 *  >> This is similar to finding the smallest window containging all characters of a small string(Pattern) in another big string(String).
 *     (Refer this link:: https://www.geeksforgeeks.org/find-the-smallest-window-in-a-string-containing-all-characters-of-another-string/)
 * 
 *  >> The difference here is that our Pattern is made of all the unique characters of the same string.
 * 
 *  >> The approach will be the same we used to solve the Pattern and String problem
 *  
 * 
 * */

string smallestUniqueString(string str){
    int strFrq[256] ={0};
    bool unqiueChars[256]={0};
    
    int numUniqueChars = 0;
    
    // count all unique characters in the string
    for (int i = 0; i < str.size(); i++) {
        if(!unqiueChars[str[i]]){
            unqiueChars[str[i]] = true;
            numUniqueChars++;
        }
    }
    
    //this will be used to mark seen characters in the string
    bool unqiueCharsSeen[256] ={0};
    int numUniqueCharsSeen =0;
    
    // start index of the current window
    int window_start = 0;
    
    int min_window_len = INT_MAX;
    int min_window_start = -1;
    
    //iterate over all the characters in the string
    for (int i = 0; i < str.size(); i++) {
        
        //calculate the frequency of the character
        strFrq[str[i]]++;
        
        //if this character has not been previously seen then mark it seen
        if(!unqiueCharsSeen[str[i]]){
            numUniqueCharsSeen++;
            unqiueCharsSeen[str[i]] = true;
        }
        
        //we found a window containging all unique characters of str
        if(numUniqueCharsSeen == numUniqueChars){
            
            //till we have atleast 1 occurance of a character we can shrink the window
            while(strFrq[str[window_start]]>1){
                strFrq[str[window_start]]--;
                window_start++;
            }
            
            //caluclate the min_window_length
            if(min_window_len > i-window_start+1){
                min_window_len = i-window_start+1;
                min_window_start = window_start;
            }
            
        }
        
    }
    
    //if present then return the substring
    if(min_window_start != -1) return str.substr(min_window_start, min_window_len);
    
    //else return "-1"
    return "-1";
    
}


int main() {
	
// 	string str = "aabcbcdbcaaad"; //dbca

    string str;
    
    getline(cin, str);
	
	cout<<smallestUniqueString(str)<<"\r\n";
	
	return 0;
}
