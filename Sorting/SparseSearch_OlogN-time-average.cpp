#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

/**
 * Question:: https://www.geeksforgeeks.org/sparse-search/
 * 
 * Given a sorted array of strings which is interspersed with empty strings, write a method to find the location of a given string.
 * Examples: 
 *  
 * Input : words[] = {"for", "geeks", "", "", "", "", "ide", "practice", "", "", "", "quiz"}
 *         word = "geeks"
 * Output : 1
 * 
 * */

// returns index of non-empty word nearest to mid
int findNearestNonEmpty(vector<string>& words, int mid, int start, int end){
    
    int left = mid-1;
    int right = mid+1;
   
   while(true){
       
       // exhausted both sides while searching then return -1
       if( left<start && right>end){
           return -1;
       }
       
       // if a non-empty string found at left then return it's index
       if(left>=start && words[left] !=""){
           return left;
       }
       
       // if a non-empty string found at right then return it's index
       if(right<=end && words[right] !=""){
           return right;
       }
       
       // traverse both left and right
       left--;
       right++;
       
   } 
   
}


int sparseSearch(vector<string> &words, string word){
    
    int start = 0;
    int end = words.size()-1;
    
    int mid;
    
    // mid index to be counted
    while(start <= end){
        
        mid = start + (end-start)/2;
        
        // if the middle word is empty then find the nearest non-empty word
        if(words[mid] == ""){
           mid = findNearestNonEmpty(words, mid, start, end);
    
            if(mid == -1) return -1;
        }
    
        // if mid index word is equal to word then we found our word
        if(words[mid] == word){
            return mid;
        }
        
        // if the word we are searching for is lexicographically smaller than the mid word then
        // search in the left part of the array
        else if( word < words[mid] ){
            end = mid-1;
        }
        
        // else search for word in the right part of the array
        else{
            start = mid+1;
        }
        
    }
    
    return -1;
}


int main() {
	
	vector<string> words{"for", "geeks", "", "", "", "", "ide", "practice", "", "", "", "quiz"};
	string word = "practice";
	
	cout<< sparseSearch(words, word) <<"\n";
	
	return 0;
}
