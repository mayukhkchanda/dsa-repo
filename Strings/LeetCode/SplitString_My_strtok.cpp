#include <iostream>
#include <cstring>
using namespace std;

/*
Implement our own string tokenization version of strtok() function in cpp
*/
// returns a pointer to the beginning of the token string or null if it doesnot exists
char* tokenizer(char* inputStr, char delimiter){
    
    //We use a static pointer reference to the input string.
    //Thus, we can call the function subsequent times with NULL input to the string
    //which is give us alll tokens in the string.
    //See strtok reference for how it works->https://www.cplusplus.com/reference/cstring/strtok/ 
    static char* strPtr;
    
    if(inputStr != NULL){
        strPtr = inputStr;
    }
    
    //if we reached the end of the string, return NULL
    if(*(strPtr) == '\0') return NULL;
    
    // dynamic array shud be used
    char *token = new char[strlen(strPtr)];
    
    int itr = 0;

    // scanning for beginning of a token by finding the first character that is not a delimiter
    // see https://www.cplusplus.com/reference/cstring/strtok/ for working of 'strtok'.
    while(  *(strPtr) != '\0' && *(strPtr) == delimiter ){
        strPtr++;
    }
    
    
    while( *(strPtr) != '\0' ){
        
        if(*(strPtr) != delimiter){
            token[itr++] = *(strPtr);
        }
        else{
            token[itr] = '\0';
            strPtr++;
            return token;
        }
        
        strPtr++;
    }
    token[itr] = '\0';
    return token;
}

void tokenize(char *str, char delimiter){
    
    char* tokenPtr = tokenizer(str, delimiter);
        
    while(tokenPtr != NULL){
        cout<<tokenPtr<<" "<<strlen(tokenPtr)<<"\n"; //can use length to check if tokenPtr is empty or not
        tokenPtr = tokenizer(NULL, delimiter);
    }
}

int main() {
	char str[1000];
	
	cin.getline(str,1000);

	tokenize(str, ' ');
	
	return 0;
}
