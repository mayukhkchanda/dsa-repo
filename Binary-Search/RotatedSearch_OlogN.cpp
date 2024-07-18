#include <iostream>
#include <vector>
using namespace std;

/**
 * Question:: https://leetcode.com/problems/search-in-rotated-sorted-array/
 * 
 * nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting
 * array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed).
 * For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].
 * 
 * Given the array nums after the rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.
 * 
 * You must write an algorithm with O(log n) runtime complexity.
 * 
 * Example 1:
 *   Input: nums = [4,5,6,7,0,1,2], target = 0
 *   Output: 4
 * Example 2:
 *   Input: nums = [4,5,6,7,0,1,2], target = 3
 *   Output: -1
 * 
 * Approach:: 
 *  > There are 2 halves that created due to pivot element. In the left half nums[k], nums[k+1], ..., nums[n-1] is sorted is ascending order.
 *      The right half nums[0], nums[1], ..., nums[k-1]] is also sorted in ascending order and nums[0] is the pivot.
 *  > Now the mid can lie in either part left or right. If nums[start] < nums[mid] then we are in the left halve of the pivot. Else if   
 *      nums[mid] > nums[end] we are in the right halve(elements are distinct). 
 *  > If mid is in the left halve, then nums[start] to nums[mid] is sorted in ascending order. Else if mid is in the right halve,
 *      then nums[mid] to nums[end] is sorted in ascending order.
 *  > In each halve we check if target lies in the sorted part(refer previous point). If so we update the start and end accordingly
 *  > Finally, if target is found we return the index.
 * 
 * */


// array contains distinct elements
int search(vector<int> array, int target){
    
    int start = 0;
    int end = array.size()-1;
    
    while(start <= end){
        
        int mid = start + (end - start)/2;
        
        //if mid index is the target return it
        if( array[mid] == target ){
            return mid;
        }
        
        // if mid lies on the right part of the pivot
        if(array[mid] < array[start]){
            // we are sure that mid to end is sorted in ascending order
            
            // if target lies in the sub-array mid to end then
            // shrink array start to mid+1
            if( array[mid] < target  && target <= array[end]){
                start = mid+1;
            }else{
                end = mid-1;
            }
            
        }
        
        // if mid lies on the left part of the pivot
        else {
            // we are sure that start to mid is sorted 
            
            // if target lies in the sub-array start to mid then
            // shrink array end to mid-1
            if( array[start] <= target  && target < array[mid]){
                end = mid-1;
            }else{
                start = mid+1;
            }
            
        } 
    }
    
    // if not found inside the binary search function then return -1
    return -1;
}


int main() {
	
	vector<int> array;
	
	int target;
	
	cin >> target ;
	
	int temp;
	
	while(cin >> temp){
	    array.push_back(temp);
	}
	
	cout<<search(array, target)<<"\n";
	
	return 0;
}
