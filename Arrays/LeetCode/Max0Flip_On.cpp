#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

/**
 * Question:: https://www.geeksforgeeks.org/maximize-number-0s-flipping-subarray/
 * 
 * Given a binary array, find the maximum number of zeros in an array with one flip of a subarray allowed.
 * A flip operation switches all 0s to 1s and 1s to 0s.
 *    Examples:
 *    
 *    Input :  arr[] = {0, 1, 0, 0, 1, 1, 0}
 *    Output : 6
 *    We can get 6 zeros by flipping the subarray {1, 1}
 *    
 *    Input :  arr[] = {0, 0, 0, 1, 0, 1}
 *    Output : 5
 * 
 * Approach:: 
 *  
 *  > Consider all 0's as -1 and all 1's as +1. Thus, we wil have an array with only -1 and +1.
 *  > Now we try to find the maximum subarray sum in this converted array. This is because all 0's after flipping
 *      will be 1 and 1's will be 0. Thus we are try to find a sub-array, that will contain maximum zeros after flipping.
 *      As this array would also have maximum 1's before flipping so we consider them as +1. And as the 0's will be 
 *      converted to 1's so we they will decrease the maximumZeros in the sub-array after being flipped. So, we consider 0's as -1.
 *      And after that all that's left to do it calculated the maximum sum in the converted array.
 *  > As our number of 0's would ultimately increase after flipping(if needed) so we return (Original_Zeros + max_sum) as the result
 *  > Good stack-overflow explanation:: https://stackoverflow.com/questions/20993454/find-number-of-bits-to-be-flipped-to-get-maximum-1s-in-array
 * */

int maximumZeros(vector<bool> array){
    
    int sum = 0;
    int max_sum = 0;
    
    int countZero = 0;
    
    int curr_val;
    
    // iterate over array and consider every 0 => -1 and 1 => 1
    for (int i = 0; i < array.size(); i++) {
        
        countZero += array[i] ? 0 : 1;  
        
        // if array[i] is 1 -> 1 and array[i] 0 -> -1
        curr_val = array[i] ?  1 : -1;
        
        // same as maximum sub-array sum in an array
        sum = sum > 0 ? sum + curr_val : curr_val;
        max_sum = max(max_sum, sum);
    }
    
    return countZero + max_sum;
}


int main() {
	
	vector<bool> array;
	
	bool temp;
	
	while(cin >> temp){
	    array.push_back(temp);
	}
	
	cout<<"\n"<< maximumZeros(array) <<"\n";
	
	return 0;
}
