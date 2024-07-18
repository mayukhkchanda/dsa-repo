#include <iostream>
#include <string>
#include <cstring>
using namespace std;

/**
 * 
 * Question:: https://leetcode.com/problems/string-compression/
 * Write a function to perform basic string compression using the counts of repeated characters, also known as Run Length Encoding. 
 * Let see one example, the input string "aaaabcccccaaa" would become "a4b1c5a3". If the "compressed" string would not become smaller 
 * than the original string, your function should return the input string. You can assume the string has only uppercase and lowercase letters.
 * You may use the to_string(int) method to convert an integer into string.
 * 
 * Sample Input::
 * sbbbaaaadexxxxxx
 * abc
 * 
 * Sample Output::
 * sb3a4d1e1x6
 * abc
 * 
 * Approach:: 
 *   Iterate over the string from left to right. Now for every character that is repeated continously,
 *   we would keep incrementing i inside an inner loop and keep incrementing the count of that character.
 *   Once we find a non-matching character, we would stop the inner loop. Now we append to the new string
 *   the character and it's count. 
 *   
 *   At the end, we check to see if the new string's length is smaller than the original string else we return the 
 *   original string.
 * 
 * */
 
string compressString(const string &str){
    
    // string are dynamically allocated. Read more here -> https://stackoverflow.com/questions/28828961/dynamically-allocate-string-literal
    string newString="";
    
    int n = str.size();
    
    for (int i=0; ; i < n; i++) {
        int count =1;
        while(i<n-1 && str[i] == str[i+1]){
            count++;
            i++;
        }
        newString = newString+str[i]+to_string(count);
    }
    
    if(newString.length() < str.length())
        return newString;
    else
        return str;
    
}

int main() {
	// your code goes here
	return 0;
}
