/**
Question: https://leetcode.com/problems/plus-one/
         https://www.interviewbit.com/problems/add-one-to-number/

You are given a large integer represented as an integer array digits,
where each digits[i] is the ith digit of the integer. The digits are
ordered from most significant to least significant in left-to-right order. 
The large integer does not contain any leading 0's.

Increment the large integer by one and return the resulting array of digits.

Example 1:
    Input: digits = [1,2,3]
    Output: [1,2,4]
    Explanation: The array represents the integer 123.
                Incrementing by one gives 123 + 1 = 124.
                Thus, the result should be [1,2,4].
Example 2:
    Input: digits = [4,3,2,1]
    Output: [4,3,2,2]
    Explanation: The array represents the integer 4321.
                Incrementing by one gives 4321 + 1 = 4322.
                Thus, the result should be [4,3,2,2].

Constraints:
    1 <= digits.length <= 100
    0 <= digits[i] <= 9
    digits does not contain any leading 0's.
*/

vector<int> plusOne(vector<int> &A) {

    int n = A.size();
    vector<int> result;
    
    int total = A[n-1] + 1;
    
    int sum = total%10;
    int carry = total/10;
    
    result.push_back(sum);
    
    // incase the array has leading zeros take the left-most no-zero number
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