#include <iostream>
#include <vector>
#include <cstring>
#include <string>
using namespace std;

/*
strtok::
    If a token is found, a pointer to the beginning of the token.
    Otherwise, a null pointer. A null pointer is always returned when
    the end of the string (i.e., a null character) is reached in the string being scanned.

Cpp docs:: https://www.cplusplus.com/reference/cstring/strtok/
*/

void tokenization(char *str){
    
    char *tokenPointer = strtok(str," ,-.");
    
    while(tokenPointer != NULL){
        cout<<tokenPointer<<"\n";
        // continue returning tokens from previous string
        tokenPointer = strtok(NULL," ,-.");
    }
    
}

int main() {
	
	char str[1000];
	
	//get the string from input
	cin.getline( str, 1000);
	
	tokenization(str);
	
	return 0;
}
