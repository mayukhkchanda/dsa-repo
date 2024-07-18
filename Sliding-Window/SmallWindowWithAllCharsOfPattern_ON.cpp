#include <iostream>
#include <vector>
#include <cstring>
#include <climits>
using namespace std;

/**
 * Question:: https://www.geeksforgeeks.org/find-the-smallest-window-in-a-string-containing-all-characters-of-another-string/
 * Given two strings S and P. Find the smallest window in the S consisting of all the characters of P.
 *   Example 1:
 *      INPUT:
 *       String = "timetopractice"
 *       Pattern = "toc"
 *      OUTPUT: 
 *       toprac
 *      Explanation: 
 *        "toprac" is the smallest substring in which "toc" can be found.
 * 
 * Approach::
 *  >> Put all characters of Pattern and their count in a hashmap(can use an array with 256 length for all english characters, whitespaces and special characters for this). 
 *  >> Iterate over the String and put each character with their frequency in the another hashmap.
 *  >> Have a window_len variable and increase it's value whenever a character in the big string is present 
 *      in the small string and its frequency till that index is less than equal to the frequency in Pattern.
 *  >> If the count becomes equal to the Pattern length then we have found a window matching our criteria.
 *  >> We can now shrink the window size by eliminating the characters from the start of the window untill the 
 *      window_len is equal to Pattern_length.
 *  >> We store the minimum window size of them all.
 * 
 * */


int smallestWindow(string String, string Pattern){
    
    //consdering only english characters and whitespaces
    int strFreq[256] = {0}; //frequency map for characters in the String
    int patFreq[256] = {0}; //frequency map for characters in the Pattern
    
    // storing all the characters and their frequency in a frequency map
    for (int i = 0; i < Pattern.size(); i++) {
        patFreq[(int)Pattern[i]]++;
    }
    
    int charsMatched = 0;// # of characters matched
    
    int min_window_len=INT_MAX;  // Size of the minimum window 
    int min_window_start=-1;     // start index of minimum window
    
    int window_start =0; // start of the current window
    
    //iterate over the String's characters
    for (int i = 0; i < String.size(); i++) {
        
        //include the current character in the window and
        //update its frequency in frequency map for String 
        strFreq[String[i]]++; 
        
        //increase the count of characters matched if this character belongs to pattern and  
        //till it's frequency matches the frequency in Pattern
        if(patFreq[String[i]]>0 && strFreq[String[i]]<=patFreq[String[i]])
            charsMatched++;
        
        //if the number of characters matched is equal to the Pattern's length, then we have 
        //matched all character of Pattern. We can start contracting the window_len and record 
        //the minimum length of them all
        while(charsMatched == Pattern.size()){
            
            //decrease the frequency of the character since we are removing this character
            strFreq[String[window_start]]--;

            //keep removing characters until possible and update the min_window_len
            if(min_window_len > i-window_start+1 ){
                min_window_len = i-window_start+1;
                min_window_start= window_start;
            }
            
            //if this character existed in pattern and it's frequency decreased then reduced the # of characters matched
            if(patFreq[String[window_start]]>0 && strFreq[String[window_start]]<patFreq[String[window_start]])
                charsMatched--;
            
            window_start++;
        }
    }
    
    if(min_window_start != -1) cout<<String.substr(min_window_start, min_window_len)<<"\n";
    
    return (min_window_len == INT_MAX ? -1 : min_window_len) ;
}


int main() {
	
// 	string bigStr = "luullulo";
// 	string smallStr = "uullo";
	
	string bigStr;
	string smallStr;
	
	getline(cin, bigStr);
	getline(cin, smallStr);
		
	cout<<smallestWindow(bigStr, smallStr);
	
	return 0;
}

