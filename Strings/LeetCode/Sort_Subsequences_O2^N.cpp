#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

/** Given, a string, generate all its Permutations and sort them by
 *  length. If lengths are equal, sort them lexiographically.
 *  INPUT:: string = "abcd"
 *  OUTPUT:: { '',a,b,c,d,ab,ac,ad,bc,bd,cd,abc,abd,acd,bcd,abcd }
 * 
 *  Time Complexity is:: O(2^N) to generate all substrings of str
 * 
 */

// recursive function to generate all substrings of a string
void Permutations(string str,string permutation,vector<string> &allPermutations, int start, int length){
    
    if(start >= length ){
        // cout<<permutation<<"\n";
        allPermutations.push_back(permutation);
        
        return;
    }
    
    //for every character in the string from start to end, we have 2 choices:
    //Either include the character or exclude the character in that permutation

    //exclude the character in this Permutation 
    Permutations(str, permutation, allPermutations, start+1, length);
    
    //include the character in this permutation
    permutation+=str[start];
    Permutations(str, permutation, allPermutations, start+1, length);

}

// recursive function to generate all substrings of a string
// more elegant approach
void Permutations2(string str,string permutation,vector<string> &allPermutations){
    
    //base case
    if(str.size() == 0 ){
        // cout<<permutation<<"\n";
        allPermutations.push_back(permutation);
        
        return;
    }
    
    //for every character in the string from start to end, we have 2 choices:
    //Either include the character or exclude the character in that permutation

    //exclude the character in this Permutation 
    Permutations2(str.substr(1), permutation, allPermutations);
    
    //include the character in this permutation
    permutation+=str[0];
    Permutations2(str.substr(1), permutation, allPermutations);

}

// Compares first by size and if sizes are equal then compares lexicographically
bool comparator(string str1, string str2){
    if(str1.size() == str2.size()) {
        return str1<str2;
    }
    
    return str1.size() < str2.size();
}

void permuteString(string str){
    
    vector<string> allPermutations;
    
    // Permutations(str, "", allPermutations, 0, str.size());
    Permutations2(str, "", allPermutations);
    
    sort(allPermutations.begin(), allPermutations.end(), comparator);
    
    
    for (auto p : allPermutations) {
        cout<<p<<"\r\n";
    }
    
}


int main() {
	string str = "abcd";
	
	permuteString(str);
	
	return 0;
}
