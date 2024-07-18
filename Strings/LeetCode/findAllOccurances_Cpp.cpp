#include <iostream>
#include <string>
#include <vector>
using namespace std;

//find the starting index of all occuranences of a string in another
// string::find -> http://www.cplusplus.com/reference/string/string/find/
vector<int> findAllOccurances(string bigString, string smallString){
    
    int indexAt=0; 
    vector<int> startIndexes;
    
    while(true){
        indexAt = bigString.find(smallString, indexAt);
        
        if(indexAt == -1) break;
        
        startIndexes.push_back(indexAt);
        indexAt++;
    }
    
    return startIndexes;
}


int main() {
    
    string bigString = "I liked the movie, acting in movie was great!";
    string smallString = "movie";
    
    vector<int> startIndexes = findAllOccurances(bigString, smallString);
    
    for (auto i : startIndexes) {
        cout<<i<<" ";
    }
    
	return 0;
}
