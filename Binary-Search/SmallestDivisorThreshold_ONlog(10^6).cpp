#include <iostream>
#include <climits>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;


/**
 * Qestion:: https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/
 * 
 * Given an array of integers nums and an integer threshold, we will choose a positive integer divisor, 
 * divide all the array by it, and sum the division's result. Find the smallest divisor such that the result
 * mentioned above is less than or equal to threshold.
 * Each result of the division is rounded to the nearest integer greater than or equal to that element.(For example: 7/3 = 3 and 10/2 = 5).
 * It is guaranteed that there will be an answer.
 * 
 * Example 1:
 *   Input: nums = [1,2,5,9], threshold = 6
 *   Output: 5
 *   Explanation: We can get a sum to 17 (1+2+5+9) if the divisor is 1. 
 *   If the divisor is 4 we can get a sum of 7 (1+1+2+3) and if the divisor is 5 the sum will be 5 (1+1+1+2). 
 * Example 2:
 *   Input: nums = [44,22,33,11,1], threshold = 5
 *   Output: 44
 * Example 3:
 *   Input: nums = [21212,10101,12121], threshold = 1000000
 *   Output: 1
 * 
 * !! This question is similar to a series of question discussed in the posts below::
 *      ->https://leetcode.com/problems/koko-eating-bananas/discuss/769702/Python-Clear-explanation-Powerful-Ultimate-Binary-Search-Template.-Solved-many-problems.
 *      https://medium.com/swlh/binary-search-find-upper-and-lower-bound-3f07867d81fb
 *      https://www.topcoder.com/thrive/articles/Binary%20Search
 * 
 * Approach:: 
 *  > If the divisor is greater the sum of elements in nums will decrease after division else it will increase.
 *      Hence, we can create a function that is monotonous w.r.t a given divisor. 
 *  > Thus sumAfterDivision is monotonous with respect to divisor and we can apply Binary search here.
 * 
 * 
 * 
 * */

// return the sum of elements after division of each element
int sumAfterDivision(vector<int>& nums, int divisor){
    
    int sum = 0;
    
    for (int i : nums) {
        // must do floating point division else ceil will not work
        sum += ceil( (float)i/ (float)divisor );
    }
    return sum;
}


int smallestDivisor(vector<int>& nums, int threshold) {
    
    int left = 1;
    int right = INT_MIN;
    
    for (int i : nums) {
        right = max(i, right);
    }
    
    while( left < right ){
        
        int mid = left + (right - left)/2;
        
        // If the sum after division is less than or equal to threshold then mid might be an answer.
        // Since we are trying to find the minimum statifying number we need to increase the sum in next
        // iteration. Thus we decrease our search space to left to mid. Else if it is greater then we
        // know that left to mid range cannot include an answer. Thus we search in mid+1 to right range.
        if(sumAfterDivision(nums, mid) <= threshold){
            right = mid;
        }else{
            left = mid+1;
        }
    }
    return left;
}

int main() {
	
	
	vector<int> nums;
	int threshold ;
	cin >> threshold;
	
	int temp;
	
	while(cin >> temp){
	    nums.push_back(temp);
	}
	
	cout<< smallestDivisor(nums, threshold)<<"\n";
	
	return 0;
}
