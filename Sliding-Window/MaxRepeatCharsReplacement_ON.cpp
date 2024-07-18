#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * Question:: https://leetcode.com/problems/longest-repeating-character-replacement/
 * 
 * You are given a string s and an integer k. You can choose any character of the string and 
 * change it to any other uppercase English character. You can perform this operation at most k times.
 * 
 * Return the length of the longest substring containing the same(all characters in substring should be same) letter 
 * you can get after performing the above operations.
 * 
 *   Input: s = "AABABBA", k = 1
 *   Output: 4
 *   Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
 *   The substring "BBBB" has the longest repeating letters, which is 4.
 * 
 * 
 *  Great Explanation:: https://leetcode.com/problems/longest-repeating-character-replacement/discuss/91285/Sliding-window-similar-to-finding-longest-substring-with-k-distinct-characters
 * 
 * */
 

int maxInArray(vector<int> arr){
    int max = 0;
    
    for (int i = 0; i<arr.size() ; i++) {
        max = max > arr[i] ? max : arr[i];
    }
    
    return max;
} 


int characterReplacement(string str, int charsReplaceable) {
        
    int left=0;  // Start of a window
    int right=0; // End of a window
    
    int maxFrqOfSameChars = 0;
    
    int maxLengthOfSameCharsSubStr = 0;
    
    // as string contains only uppercase chars
    vector<int> charFrq(26, 0);
    
    while(right < str.size()){
        
        // expanding window by including this character's frequency
        charFrq[str[right]-'A']++;
        
        //calculate the maximum frequency of same characters in the string
        maxFrqOfSameChars = max(charFrq[str[right]-'A'], maxFrqOfSameChars); 
        
        //  if the (length of subtring - max Frq Of Same Chars) in the subtring becomes greater than k
        //  then we cannnot change any more Chars in this subtring to make all Chars same. Thus
        //  we shrink the size of the subtring
        while( (right-left+1)-maxFrqOfSameChars > charsReplaceable ){
            
            charFrq[str[left]-'A']--;
            left++;
            
            maxFrqOfSameChars = maxInArray(charFrq);
        }
        
        if(maxLengthOfSameCharsSubStr < right-left+1){
            maxLengthOfSameCharsSubStr = right-left+1;
        }
        
        right++;
    }
        
    
    return maxLengthOfSameCharsSubStr;
}

int main() {
	string str="ABCD"; //= "AABABBA";
	int k = 2; //=1;
	
// 	cin >> k;
	
// 	getline(cin, str);
	
	cout<< characterReplacement(str, k);
	
	return 0;
}
