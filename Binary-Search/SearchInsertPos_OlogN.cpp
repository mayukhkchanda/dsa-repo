#include <iostream>
#include <vector>
using namespace std;

/**
 * 
 * Question:: https://leetcode.com/problems/search-insert-position/
 * 
 * Given a sorted array of distinct integers and a target value, return the index if the
 * target is found. If not, return the index where it would be if it were inserted in order.
 * You must write an algorithm with O(log n) runtime complexity.
 * Example 1:
 *   Input: nums = [1,3,5,6], target = 5
 *   Output: 2
 * 
 * 
 * !! This question is similar to a series of question discussed in the posts below::
 *      https://leetcode.com/problems/koko-eating-bananas/discuss/769702/Python-Clear-explanation-Powerful-Ultimate-Binary-Search-Template.-Solved-many-problems.
 *      https://medium.com/swlh/binary-search-find-upper-and-lower-bound-3f07867d81fb
 *      https://www.topcoder.com/thrive/articles/Binary%20Search
 * 
 * Approach::
 *  > we are trying to find the first number x in the array nums that is >= target. This is
 *      because if this number == target then we found the target else we know that every number
 *      before this number is less than target and if inserted it would be placed in this position.
 *  > This is similar to lower bound binary search.
 * 
 * */


int searchInsert(vector<int>& nums, int target) {
        
    int left = 0;
    int right = nums.size();
    
    while(left < right){
        int mid = left + (right - left)/2;
        
        if(nums[mid] < target){
            left = mid +1;
        }else{
            right = mid;
        }                
    }
    
    return left;        
}


int main() {
	
	
	vector<int> nums;
	int target ;
	cin >> target;
	
	int temp;
	
	while(cin >> temp){
	    nums.push_back(temp);
	}
	
	cout<< searchInsert(nums, target)<<"\n";
	
	return 0;
}
