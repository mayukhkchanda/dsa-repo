#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

/**
Split a string into tokens based on a particular character.
GFG Article:: https://www.geeksforgeeks.org/stringstream-c-applications/
StringStream Article:: https://www.geeksforgeeks.org/removing-spaces-string-using-stringstream/
Multiple Delimiters:: https://stackoverflow.com/questions/7621727/split-a-string-into-words-by-multiple-delimiters
*/

void tokenization(string str){
    
    stringstream strStream(str);
    
    string tokens;
    
    while(getline(strStream, tokens, ',')){
        cout<<tokens<<" ";
    }
    
    
}

int main() {
	
	string str;
	
	//get the string from input
	getline(cin, str);
	
	tokenization(str);
	
	return 0;
}
