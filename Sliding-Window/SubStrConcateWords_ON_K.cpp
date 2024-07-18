#include <iostream>
#include <vector>
#include <cstring>
#include <unordered_map>
using namespace std;

/**
 * Question:: https://leetcode.com/problems/substring-with-concatenation-of-all-words/
 * 
 * You are given a string s and an array of strings words of the same length. Return all starting indices of substring(s) 
 * in s that is a concatenation of each word in words exactly once, in any order, and without any intervening characters.
 * You can return the answer in any order.
 * 
 * Example 1:
 *   Input: s = "barfoothefoobarman", words = ["foo","bar"]
 *   Output: [0,9]
 *   Explanation: Substrings starting at index 0 and 9 are "barfoo" and "foobar" respectively.
 *   The output order does not matter, returning [9,0] is fine too.
 *
 * Example 2:
 *   Input: s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]
 *   Output: []
 *
 * Example 3:
 *   Input: s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]
 *   Output: [6,9,12]
 * 
 * Great ExplanationL:: https://leetcode.com/problems/substring-with-concatenation-of-all-words/discuss/13658/Easy-Two-Map-Solution-(C%2B%2BJava)
 * 
 * Approach::
 *  > run a loop over the string and for every index use an inner for loop to check if the substring starting at that index
 *      and having length words[0](all words are of same length) is present in words array(use a hashmap for this)
 *  > Keep checking the above condition untill we encounter a word that is not present in array or an word has a
 *      higher frequency in str than in words array. 
 *  > If after the inner loop ends the pointer has moved till the end of nums_size then we found a valid substring & store it's index
 *  > We repeat this process for every character in string until [len_str-( len_words * words[0].size() )] 
 * 
 * Time complexity is:: O(n*k) where n -> size of string & k -> size of words array
 * 
 * Space complexity isL:: O(2*K) =~(equivalent to) O(K) [at any point we have 2 unordered_map that store atmost num_words number of words and their frequency]
 * 
 * */

vector<int> findSubstring(string str, vector<string>& words) {
    
    // store word-frequency map of words
    unordered_map<string, int> word_map ;
    
    for (auto word : words) {
        word_map[word]++;
    }
    
    int num_words = words.size();
    int len_word = words[0].size();
    
    int len_str = str.size();
    
    vector<int> start_indexes;
    
    // iterate over str from 0 till  len_str - (number of words * length of a word[all words are of same length])+1
    for (int i = 0; i < len_str-(num_words * len_word)+1 ; i++) {  // bounded by O(N) in time
        
        unordered_map<string, int> seenWord_map;
        
        // run an inner loop starting from i and extract each subtring consecutively until:
        // inner loop reaches end OR a we encounter a word that is not present in words OR 
        // -a word has higher frequency than in words
        int j = 0;
        
        for (; j < num_words; j++) {  // bounded by O(K) in time
            
            string seenWord = str.substr( i+(len_word*j), len_word );
            
            seenWord_map[seenWord]++;
            
            // if this word exists in words array and it's frequency is less than or equal to 
            // the frequency words array then we continue the loop else we break
            if( !(word_map.count(seenWord) > 0  && seenWord_map[seenWord]<=word_map[seenWord]) ){
                break;
            }
        }
        
        // if all words in words array have been matched then we found a starting index
        if(j == num_words){
            start_indexes.push_back(i);
        }
    }
    
    return start_indexes;
}

int main() {
	string str = "barfoothefoobarman";
	vector<string> words = {"foo","bar"};
	
	vector<int> valid_indexes = findSubstring(str, words);
	
	for (auto i : valid_indexes) {
	    cout<< i<<" ";
	}
	
	return 0;
}
