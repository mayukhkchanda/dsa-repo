#include <iostream>
#include <string>
using namespace std;
/**
 Implement our own str.replace(string oldChar, string newChar) in cpp. Here oldChar is ' '.
 Should be inplace and linear in time.
*/
void replaceSpaces(char *str, string strToReplaceWith){
    
    int spaces=0;
    int length=0;
    //calculate the number of spaces and length of the string
    for (int i = 0; str[i] != '\0' ; i++) {
        length++;
        if(str[i] == ' ') spaces++;
    }
    
    
    // calculate the new end index based on the number of additional characters required
    // we need the new string's length-1 number of new space for each space character
    int newEndIndex = length+ (strToReplaceWith.length()-1)*spaces;
    
    str[newEndIndex] = '\0';
    
    //iterate over the string from end and keep on putting the characters to the 
    //new end index. if the character is a space character then we replace that
    //with strToReplaceWith by putting the characters of the string to replace from end
    for (int i = length-1; i >=0; i--) {
        if(str[i] != ' '){
           //if the current character is not a space character then put it as it is.
            str[--newEndIndex] = str[i];
        }
        else{
            //Else put the newString by iterating from backwards
            for (int j = strToReplaceWith.length()-1; j>=0; j--) {
                str[--newEndIndex] = strToReplaceWith.at(j);
            }
        }
        
    }
    
    
}

int main() {
	char str[1000];
	string strToReplaceWith = "%20";
	
	cin.getline(str,1000);
	
	replaceSpaces(str, strToReplaceWith);
	
	cout<<"\r\n"<<str;
	
	return 0;
}
