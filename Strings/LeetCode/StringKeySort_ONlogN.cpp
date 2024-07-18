#include <iostream>
#include <cstring>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

/*

Given, n string with equal # of space separated numeric values, sort the strings based on a
particular column when splited w.r.t spaces. Columns are 1-indexed. If 'numeric' is specified
then sort the strings based on their numeric values. If 'lexiographically' is specified, then
sort the strings based on dictionary order i.e. 00 comes first then 11 ,22 and so on.
Reverse the output if true is given.

Sample Input
------------
3
92 022
82 12
77 13
2 false numeric

Sample Output
-------------
82 12
77 13
92 022
*/


//sort by numeric value
bool sortByNumber(const pair<string, int> &a, const pair<string, int> &b){
    return stoi(a.first) < stoi(b.first);
}

//tokenize a string based on spaces and return the vector of tokens
vector<string> tokenize(string str){
    stringstream stringStream(str);
    
    vector<string> tokens;
    
    string token;
    
    while(getline(stringStream, token, ' ')){
        
        tokens.push_back(token);
    }
    return tokens;
}

vector<string> sortStrings(vector<string> &strings, int column, bool reversed, string sortBy){
    
    //to store string's column value and their index 
    //used while and after sorting
    // vectors are dynamically allocated internally by the vector class
    // https://stackoverflow.com/questions/6775643/allocating-vectors-or-vectors-of-vectors-dynamically
    vector<pair<string, int>> elIndx;
    
    //for each string in the input,split it and put the column numeric string in a 
    //pair along with its index and store it in a vector to be sorted
    for (int i = 0; i < strings.size(); i++) {
        vector<string> tokens = tokenize(strings[i]);
        elIndx.push_back({tokens[column-1],i});
    }
    
    if(sortBy.compare("numeric") == 0)
        sort(elIndx.begin(), elIndx.end(), sortByNumber);
    else
        sort(elIndx.begin(), elIndx.end());
    
    vector<string> resultVector;
    
    if(!reversed){
        for (auto el : elIndx) {
            resultVector.push_back(strings[el.second]);
        }
    }else{
        for (int i = elIndx.size()-1; i >=0 ; i--) {
            resultVector.push_back(strings[elIndx[i].second]);
        }
    }
    return resultVector;
    
}



int main() {
	
	vector<string> inputs;
	
	string str;
	
	while(getline(cin, str)){
	    inputs.push_back(str);
	}
	
	int column=2;
	bool reversed = false;
	string sortBy = "numeric";
	
	vector<string> sortedStrings = sortStrings(inputs, column, reversed, sortBy);
	
	for (auto i : sortedStrings) {
	    cout<<i<<"\n";
	}
	
	
	return 0;
}
