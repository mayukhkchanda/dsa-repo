#include <iostream>
using namespace std;

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * Question:: https://leetcode.com/problems/largest-number/
 * Given a list of non-negative integers nums, arrange them such that they form the largest number.
 *
 * Note: The result may be very large, so you need to return a string instead of an integer. -> stoi(string) will not work here
 *    
 *    Example 1:
 *    Input: nums = [10,2]
 *    Output: "210"
 *    
 *    Example 2:
 *    Input: nums = [3,30,34,5,9]
 *    Output: "9534330"
 * 
 * Approach::
 * we just need to figure out few case and write our sorting comparator keeping those in mind.
 * Let's take 2 numbers : num1 & num2 we will base our cases based on these 2 numbers
 * 
 * !!NOTE:: Here concatenate means string concatenation that is 1+1= 11. Even if num1 & num2 are integers, 
 *          they should be joined as a string. !!
 * 
 * We can concatenate num1 & num2 in 2 ways -> num1+num2 or num2+num1.
 * Here, we do a string comparision after concatenation i.e. "1">"2" type of comparision.
 * 
 * Case 1:: num1 = 3 & num2 = 320. so num1+num2=3320 and num2+num1=3203. 
 *          Here 3320 > 3203, so num1 should be placed before num2       
 * 
 * Case 2:: num1 = 3 & num2 = 345. so num1+num2=3345 and num2+num1=3453. 
 *          Here 3345 < 3453, so num2 should be placed before num1        
 * 
 * Case 3:: num1 = 3 & num2 = 400. so num1+num2=3400 and num2+num1=4003.
 *          Here 3400 < 4003, so num2 should be placed before num1    
 * 
 * Case 4:: num1 = 3 & num2 = 333. so num1+num2=3333 and num2+num1=3333.
 *          Here 3333 = 3333, so it doesn't matter where we place num1 & num2 
 * 
 * We will use the above cases to write the logic for our sorting comparator.
 * That is, if num1+num2 > num2+num1 --> If this returns true, num1 should be placed before num2
 * else num2 should be placed before num1. 
 * 
 * This is all the logic we need for this problem.
 * 
 * Good Explation :: https://leetcode.com/problems/largest-number/discuss/53158/My-Java-Solution-to-share
 *
 * */
 
 // if this returns true then num1 will be placed before num2 else num2 will be placed before num1
bool sortLexiograpically(int num1, int num2){
    return (to_string(num1)+to_string(num2)) > (to_string(num2)+to_string(num1)) ;
}

string largestNumber(vector<int>& numbers){
   sort(numbers.begin(), numbers.end(), sortLexiograpically);
   
   string bigestNum = "";
    
   bool isAllZeros = true;
   
   for (auto i : numbers) {
        if(i != 0){
            isAllZeros = false;
        }
        bigestNum += to_string(i);
   }
   
   return isAllZeros ? "0" :bigestNum;
}

int main() {
	
// 	vector<int> numbers{3,30,34,5,9};
	
	vector<int> numbers{3,422};
	
	cout<<"\r\n"<<largestNumber(numbers)<<"\n";
	
	return 0;
}
