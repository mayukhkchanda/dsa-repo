#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

/**
 * GFG Question:: https://www.geeksforgeeks.org/lexicographically-smallest-string-obtained-concatenating-array/
 * Exactly same question but with non-negative integers inplace of strings:: https://leetcode.com/problems/largest-number/
 * 
 * Given n strings, concatenate them in an order that produces the lexicographically smallest possible string.
 * Examples: 
 *  
 * INPUT::  a[] = ["c", "cb", "cba"]
 * OUTPUT:: cbacbc
 * 
 * Possible strings are ccbcba, ccbacb,cbccba, cbcbac, cbacbc and cbaccb. 
 * Among all these strings, cbacbc is the lexicographically smallest.
 * 
 * Input :  a[] = ["aa", "ab", "aaa"]
 * Output : aaaaaab
 * 
 * Approach Discussed in the solution for this question(https://leetcode.com/problems/largest-number/) in array section
 * 
 * 
 * */


bool comparator(string s1, string s2){
    return s1+s2 < s2+s1 ;
}

string smallestString(vector<string> &words){
    
    //sort using custom comparator
    sort(words.begin(), words.end(), comparator);
	
	string str;
	
	// after sorting append all strings in order of their appearance
	for (auto word : words) {
	    str += word;
	}
	return str;
}


int main() {
	
	vector<string> words{"a","ab","aba"};
	
	cout<< smallestString(words)<<"\n";
	
	return 0;
}
