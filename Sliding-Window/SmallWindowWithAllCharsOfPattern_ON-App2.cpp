#include <iostream>
#include <cstring>
#include <vector>
#include <unordered_map>
#include <algorithm>
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
 *    Approach:
 *      > Store the count of charactes in pattern string in a hashmap.
 *      > Iterate over the string and decrease the character count of the characters
 *        that are present in small string.
 *      > If at any point the frequency of all characters goes down and  we have no
 *        positives in the array then we can start contracting the window.
 *      > Record the minimum window size of them all
 *
 */

// returns true if the hashmap container has any positive values else returns false
bool hasPositives(auto hashmap){
    bool hasAnyPostiveVal = false;
    for (auto i : hashmap) {
        hasAnyPostiveVal = i.second>0 ? true : hasAnyPostiveVal;
    }
    return hasAnyPostiveVal;
} 

// returns length of smallest sub-string containing all characters of smallStr including duplicates
int smallestStringWindow(string bigStr, string smallStr){
    
    unordered_map<char,int> charFrq;
    
    // store the frequency of all characters in the small string
    for (int i = 0; i < smallStr.size(); i++) {
        charFrq[smallStr[i]]++;
    }
    
    int l=0; // start of window
    int r=0; // end of window
    
    int minimumWindowSize = INT_MAX; // infinity
    int minimumWindowStart = -1;
    
    while( r<bigStr.size() ) {
        
        // if a character in big string exists in small string, then decrease it's count
        if(charFrq.find(bigStr[r]) != charFrq.end()){
            charFrq[bigStr[r]]--;
            
            // if there are no positives in the map, then this window has all characters of the small string
            // we can keep shrinking the window untill the charFrq again has some positive value and take the 
            // minimum window width of them all
            while(!hasPositives(charFrq)){
                
                // minimumWindowSize = min(minimumWindowSize, r-l+1);
                if(minimumWindowSize > r-l+1){
                    minimumWindowSize= r-l+1;
                    minimumWindowStart = l;
                }
                
                if(charFrq.find(bigStr[l]) != charFrq.end()){ // only increase occurance of characters present in small string
                    charFrq[bigStr[l]]++;
                }
                l++;
            }
        }
        r++;
    }
    
    if(minimumWindowStart != -1) cout<< bigStr.substr(minimumWindowStart, minimumWindowSize)<<"\n";
    
    return minimumWindowSize;
}


int main() {
	
// 	string bigStr = "luullulo";
// 	string smallStr = "uullo";
	
	string bigStr;
	string smallStr;
	
	getline(cin, bigStr);
	getline(cin, smallStr);
	
	
	cout<<smallestStringWindow(bigStr, smallStr);
	
	return 0;
}
