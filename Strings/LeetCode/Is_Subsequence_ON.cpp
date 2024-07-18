#include <iostream>
using namespace std;

/**
https://leetcode.com/problems/is-subsequence/
Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

A subsequence of a string is a new string that is formed from the original string by 
deleting some (can be none) of the characters without disturbing the relative positions 
of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

Example 1:
    Input: s = "abc", t = "ahbgdc"
    Output: true
*/
/*
Approach::
    Have 2 pointers 1st for small string and another for big String. We keep incrementing the 
    pointer to the big String. If at an we index find the character of small String in big String we 
    increment the small String pointer to the next character. We do this untill we reach
    either string's end index. After we are out of this loop, if we have reached the end of
    the small String, then we can say that all character smallString are matched and with relative order 
    being preseved. Thus, smallString is a sub-sequence of bigString else not.
*/
bool isSubsequence(string smallString, string bigString){
    
    int j=0; //pointer to big string
    int i=0; //pointer to small string
    
    for (i = 0; i < smallString.size() && j<bigString.size(); ) {
        
        //if character of smallString exists in bigString, then increment
        //both pointer; else only increment smallString pointer
        if(smallString[i] == bigString[j]){
            j++;
            i++;
        }
        else{
            j++;
        }
        
    }
    
    //if we reached the end of the smallString, then smallString is a sub-sequence of bigString else it is not
    if(i == smallString.size()) return true;
    
    return false;
    
}

int main() {
	
	string bigString ="codingminutes";
	string smallString = "cines";
	
	bool isSubset = checkSubsets(bigString, smallString);
	
	cout<<isSubset;
	
	return 0;
}
