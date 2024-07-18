#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
using namespace std;

/**
 *  https://leetcode.com/discuss/interview-question/124659/given-a-string-with-spaces-normalize-it/126087
 * 
 *  Given a string with spaces, normalize it. This is done in normalizeModified function
 *  Input: "  hello my    wORLD    P  "
 *  Output: "Hello My World P"
 * 
 * Approach::
 *  If a character is preceeded by a whitespace character or the index = 0
 *  we  capitalize it. else we lowercase it. If a space is preceed by another
 *  space we skip it.
 *  
 * */
 
/* Will remove and normalize spaces b/w words also */
string normalizeModified(const string &sentence) {
    string copy = "";
    
    int i=0;
    
    //if there are whitespace character before the start of the string skip ahead
    while(i<sentence.size() && sentence[i] == ' '){
        i++;
    }
    
    //first character will always be uppercase
    copy += toupper(sentence[i]);
    i++;
    
    for ( ; i < sentence.size(); i++) {
        
        //if we see spaces continously, we skip through
        if(sentence[i] ==' ' && sentence[i-1] ==' ' ){
            continue;
        }
        
        //if the preceeding character is a whitespace and this character is an alphabet then only change case
        if( sentence[i-1] == ' ' && isalpha(sentence[i])){
            //uppercase this character
            copy += toupper(sentence[i]);
        }else {
            copy += tolower(sentence[i]);
        }
        
    }
    
    //if atlast we have a ' ' then replace it with '\0'
    if(copy[copy.size()-1] == ' '){
        copy[copy.size()-1]='\0';
    }

    return copy;
} 


/* Will not remove spaces in b/w words */
string normalize(const string &sentence) {
    string copy = sentence;
    
    int i=0;
    
    //if there are whitespace character before the start of the string
    //skip ahead
    while(i<sentence.size() && sentence[i] == ' '){
        i++;
    }
    
    //first character will always be uppercase
    copy[i] = toupper(sentence[i]);
    i++;
    for ( ; i < sentence.size(); i++) {
        
        //if the preceeding character is a whitespace and this character is an alphabet then only change case
        if( sentence[i-1] == ' ' && isalpha(sentence[i])){
            //uppercase this character
            copy[i] = toupper(sentence[i]);
        }else {
            copy[i] = tolower(sentence[i]);
        }
        
    }

    return copy;
}

int main() {
    
    // cout<< normalize("  this iS   SOOO much fun!  ");
    cout<< normalizeModified("  this iS   SOOO much fun!     ");
	
	return 0;
}
