#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

/**
 * https://leetcode.com/problems/custom-sort-string/
 * Example:
    Input: 
    order = "cba"
    str = "abcd"
    Output: "cbad"
    Explanation: 
    "a", "b", "c" appear in order, so the order of "a", "b", "c" should be "c", "b", and "a". 
    Since "d" does not appear in order, it can be at any position in the returned string. "dcba", "cdba", "cbda" are also valid outputs.
 * */


/**
 * the important point here is all characters x in the string str should appear before all
 * characters y in str if they appear after each other in the order string.
 * for eg-> if order is cba and string is abbcadcc, then o/p will be cccbbaad
 * Inituition:: 
 * Pre-calculate the number of characters in the array. Now iterate over the order string
 * and place all characters as the appear in a new string. In the end iterate once over
 * the character frequency array and place all the remaining characters as the appear in the 
 * end of the string.
 * */
 //O(len(str))+O(len(order)*len(str))-> time cost and O(len(str)) space cost
 //since order contains no duplicate character and only 26 alphabets, len(order) is a constant
 //so this function is bounded by O(len(str)) in space and time;
string customSortString(string order, string str) {
    
    string sortedString;
    
    //for storing charaters frequency
    vector<int> charFrq(26,0);
    
    //pre-compute the characters frequency by iterating
    //over the str 
    for (int i = 0; i < str.size(); i++) { //O(len(str)) - time complexity
        charFrq[str[i]-'a']++;
    }
    
    //iterate over the order string and keep placing all
    //the characters as they appear in the order string
    for (int i = 0; i < order.size(); i++) { //O(len(order)) - time complexity, and because of the while loop we have O(len(order)*len(str))
        
        //place all characters of a certain alphabet in order string
        //before moving to the next one
        while(charFrq[order[i]-'a']>0){ //in wrost case all characters in the string are same characters, O(len(str))
            
            sortedString.push_back(order[i]);
            charFrq[order[i]-'a']--;
        }
        
    }
    
    //iterate over the charFrq once at the end.
    //if there are any characters remaining to be placed
    //place them at the end of the string
    for (int i = 0; i < charFrq.size(); i++) {//O(c) time cost, for while loop it becomes -> O(c*len(str))
        while(charFrq[i]>0){ //O(len(str)) time cost. for eg-> abbbb...b upto len(str-1) and order is 'a'
            
            sortedString.push_back('a'+i);
            charFrq[i]--;
        }
    }
    
    return sortedString;
}

int main() {
	string order = "cba";
    string str = "abbcbdc";
    
    cout<<customSortString(order, str)<<"\n";
    
	return 0;
}
