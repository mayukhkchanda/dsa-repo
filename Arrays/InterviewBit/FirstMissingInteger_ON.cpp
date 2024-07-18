#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/**
 * 
 * Question:: https://leetcode.com/problems/first-missing-positive
 * 
 * Given an unsorted integer array nums, return the smallest missing positive integer.
 * 
 * You must implement an algorithm that runs in O(n) time and uses constant extra space.
 * Example 1:
 * Input: nums = [1,2,0]
 * Output: 3
 * Example 2:
 * Input: nums = [3,4,-1,1]
 * Output: 2
 * Example 3:
 * Input: nums = [7,8,9,11,12]
 * Output: 1
 * 
 * Nicely explained solutions ->
 *  > https://leetcode.com/problems/first-missing-positive/discuss/319270/Explanation-of-crucial-observation-needed-to-deduce-algorithm
 *  > https://leetcode.com/problems/first-missing-positive/discuss/17214/Java-simple-solution-with-documentation
 * 
 * 
 * 
 * */

int firstMissingPositive(vector<int>& nums) {
    
    int n = nums.size();
    
    /**
     * If a number or numbers is missing then the smallest of them must lie within 1 to n(size of array).
     * The array has 1 to n(size of array) buckets and if a number X(the smallest of all the number is more than 1 is missing)
     * is missing then it must be that bucket # X between 1 to n(size of array) is empty. Else if all buckets are filled then we
     * have n+1 as the missing number.
     * 
     * Eg: [3, 4, -2, 1]
     * 
     * Let's consider n empty buckets numbered 1 to n & we put each number in it's respective bucket.
     *           Indices   ___    
     *              1  -> |_1_|             
     *              2  -> |_ _|
     *              3  -> |_3_|
     *              4  -> |_4_|
     * 
     * We see that first empty bucket is 2 so 2 is our missing number. Note we consider only +ve numbers i.e. > 0.
     * Had 2 been present then all buckets would have been filled and our missing number would be 5.
     * 
     * */
    
    for (int i = 0; i < n; i++) {
        
        // we can ignore -ve numbers as they are useless
        if(nums[i] <= 0){
            nums[i] = n+1; // any number greater than n would work here    
        }
    }
    
    for (int i = 0; i < n; i++) {
        
        int hashIndx = abs(nums[i])-1; // the bucket number
        
        // any number x greater than n could not be placed in xth bucket as
        // we have only n buckets
        if(hashIndx >= n){
            continue;
        }
        
        // if a number x is less than or equal to n then it could be placed 
        // in the xth bucket(x-1 in array as indices start from 0) as we have n buckets
        if(nums[hashIndx] > 0){
            nums[hashIndx] *= -1;
        }
    }
    
    // If a non-negative number exists then it means we never found 
    // a hashIndx for that number i.e. the hashIndx+1 does not exists
    // and we return that
    for (int i = 0; i < n; i++) {
        if(nums[i] >= 0){
            return i+1;
        }
    }
    
    // else all the numbers have completely filled their respective
    // buckets and we n+1(n = size of array) is the missing integer
    return n+1;
}

int main() {
    
    vector<int> nums;
    int temp;
    while(cin >> temp) nums.push_back(temp);
    
    cout<< firstMissingPositive(nums);
	
	return 0;
}
