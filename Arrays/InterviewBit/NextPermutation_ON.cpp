#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * Question:: https://leetcode.com/problems/next-permutation
 * 
 * Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
 * If such an arrangement is not possible, it must rearrange it as the lowest possible order (i.e., sorted in ascending order).
 * The replacement must be in place and use only constant extra memory.
 * 
 * Example 1:
 *   Input: nums = [2,3,6,5,4,1]
 *   Output: [2,4,1,3,5,6]
 * Example 2:
 *   Input: nums = [3,2,1]
 *   Output: [1,2,3]
 * Example 3:
 *   Input: nums = [1,3,2]
 *   Output: [2,1,3]
 * Example 4:
 *   Input: nums = [1]
 *   Output: [1]
 * 
 * Explained Solution(Comment):: https://leetcode.com/problems/next-permutation/discuss/13867/C++-from-Wikipedia/14266
 * 
 * Approach::
 *  > As the question tells us to find the largest permutation next of nums, hence if we see that nums is already
 *    in descending(effectively non-increasing at any point) order then we know that this is the largest possible permutation and
 *    so we reverse the array and return it.
 *  > If the array is not in descending order then we know that there is some index k such that nums[k] < nums[k+1]. We find the
 *    right most index of k that statisfies the condition.
 *  > Once we find k, then we know that this is the element that could be replaced to create a higher permutation.
 *    Thus we find to the right of index k(excluding itself) the first number that is greater than k from the right-end til k(exclusive).
 *    We can then swap these two elements to create an higher permutation but this is still not next to nums in dictionary order.
 *  > The elements to the right of k are still in non-increasing(descending) order and this can be reversed to create an higher
 *      permutation that is next to nums.
 * 
 * 
 * */



void nextPermutation(vector<int>& nums) {
    
    int n = nums.size();
    
    bool isDescending = true; // indicates if elements are already arranged in descending order
    
    int firstSmallElementIdxFromRight = -1; // the first index of the element from the right that breaks the descending order
    
    for (int i = n-1; i>0 ; i--) {
        
        // if we find any index i :: nums[i-1] < nums[i] for i=1 to n-1 then
        // we know that this is not the highest permutation 
        if( nums[i-1] < nums[i] ){
            firstSmallElementIdxFromRight = i-1;
            isDescending = false;
            break;
        }
    }
    
    // check if all elements are arranged in descending order, if so then nums is already arranged in the highest possible permutation
    // So reverse the array to create the lowest possible permutation
    if(isDescending){
        reverse(nums.begin(), nums.end());
        return;
    }
    
    int indexOfFirstLargestElement = -1;
    
    // else we know that there is a number that at index firstSmallElementIdxFromRight that can be
    // swapped with the least largest element to the right of it to create an higher permutation
     for (int i = n-1; i>firstSmallElementIdxFromRight ; i--) {
        
        // find the first element greater than the element at firstSmallElementIdxFromRight
        if( nums[firstSmallElementIdxFromRight] < nums[i] ){
            
            indexOfFirstLargestElement = i;
            break;
        }
    }
    
    swap(nums[firstSmallElementIdxFromRight], nums[indexOfFirstLargestElement]);
    
    // we created an higher permutation but this is not the next permutation of nums
    // we need to flip the elements in the right of firstSmallElementIdxFromRight index
    
    reverse(nums.begin()+firstSmallElementIdxFromRight+1, nums.end());
    
    
    // return nums;
}

int main() {
	
	vector<int> nums;
	int temp;
	while(cin >>temp) nums.push_back(temp);
	
	nextPermutation(nums) ;
	
	for (auto i : nums) {
	    cout<<i<<" ";
	}
	
	return 0;
}
