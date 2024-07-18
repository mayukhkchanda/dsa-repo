#include <iostream>
using namespace std;


/**
 * Question:: https://www.interviewbit.com/problems/add-one-to-number/
 * 
 * Given a non-negative number represented as an array of digits,
 * add 1 to the number ( increment the number represented by the digits ).
 * The digits are stored such that the most significant digit is at the head of the list.
 * 
 * Example:
 * If the vector has [1, 2, 3] the returned vector should be [1, 2, 4] as 123 + 1 = 124.
 * 
 * NOTE: Certain things are intentionally left unclear in this question which you should practice asking the interviewer.
 * For example, for this problem, following are some good questions to ask :
 *   Q : Can the input have 0’s before the most significant digit. Or in other words, is 0 1 2 3 a valid input?
 *   A : For the purpose of this question, YES
 *   
 *   Q : Can the output have 0’s before the most significant digit? Or in other words, is 0 1 2 4 a valid output?
 *   A : For the purpose of this question, NO. Even if the input has zeroes before the most significant digit.
 * 
 * Approach::
 *  > Add 1 to the least significant digit i.e the tail of the array. Store the digit to be placed as sum and carry.
 *  > Now iterate over the remaining array starting from n-2 to the most significant digit's index(this might not be
 *      the 0th index because of leading zeros e.g [0,1,2,4]).
 *  > Keep adding the carry to each digit and calculate the sum and carry for each of them.
 *  > In the end if carry is > 0 then add another digit to the result.
 *  > Finally, reverse the array as we are push the most significant digit to the front alway. 
 * 
 * */


vector<int> plusOne(vector<int> &A) {

    int n = A.size();
    vector<int> result;
    
    // add 1 to the least significant digit i.e the end element of the list
    int total = A[n-1] + 1;
    
    // the digit that wil be placed in this place is given by % 10 and carry by /10
    int sum = total %10;
    int carry = total / 10;
    
    // push_back the least significant digit(makes insertion easier). We will reverse the array before returning.
    result.push_back(sum);
    
    // calculate the most significant digit's index(might not be the 0th index if there are leading 0's)
    int msb_indx = 0;
    while( msb_indx < n &&  A[msb_indx] == 0 ){
        msb_indx++;
    }

    // start from least significant digit i.e. tail of the list
    for(int i=n-2; i>=msb_indx ;i--){
        
        // add carry to the digit   
        total = A[i]+carry;
        
        // calculate sum(this is the digit that is to be placed here) and carry
        sum = total %10;
        carry = total /10;
        
        // push_back sum
        result.push_back(sum);
    }

    // if we have a remaining carry then it will also be place (eg input: [9,9,9] )
    if(carry > 0){   
        result.push_back(carry);
    }
    
    // Finally reverse the list and return the result
    reverse(result.begin(), result.end());
    return result;
}



int main() {
	
	int temp;
	vector<int> A;
	
	while(cin >> temp){
	    A.push_back(temp);
	}
	
	cout<< plusOne(A) ;
	
	return 0;
}
