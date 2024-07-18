#include <iostream>
#include <vector>
using namespace std;

/**
 * Question:: https://leetcode.com/problems/move-zeroes/
 * Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
 *    Note that you must do this in-place without making a copy of the array.
 *    Example 1:
 *        Input: nums = [0,1,0,3,12]
 *        Output: [1,3,12,0,0]
 * 
 * Approach: 
 *      1.Brute Force O(N) time:: Using 2 for loops to shift the zeros
 *      2.O(N) Space:: Using another array to store the zeros while iterating over the array- O(N) space & time
 *      
 *      3.O(1) Space:: 
 *        Intuition:: As we only need to shift zeros to the end. we can store the count of zeros and keep shifting
 *          the non-zero elements to the start using a pointer to the start of the array. 
 *        Approach:: 
 *          >> We maintain a left pointer to the begining of the array initially. And also a countZeros variable 
 *              to store the count of zeros.
 *          >> As we see a non-zero element when move the variable to the start and increment the left pointer
 *          >> We do this until the right pointer reaches the end. Finally, we put all zeros in the remaining part
                starting from the left pointer till the end of array.
 * 
 * */

void shiftZeros(vector<int> &array){
    
    int countZeros = 0;
    
    int left=0;
    int right=0;
    
    while(right < array.size()){
        
        if(array[right] != 0){
            array[left] = array[right];
            left++;
            right++;
            continue;
        }
        
        countZeros++;
        right++;
        
    }
    
    while(countZeros--){
        array[left++] = 0;
    }
    
}

int main() {
	vector<int> array{0,1,0,3,12};
	shiftZeros(array);
	
	for (auto i : array) {
	    cout<< i<<" ";
	}
	
	return 0;
}
