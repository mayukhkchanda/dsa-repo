#include <iostream>
#include <vector>
using namespace std;

/**
 * Question::
 *  Leetcode -> https://leetcode.com/problems/find-the-duplicate-number/
 *  InterviewBit -> https://www.interviewbit.com/problems/find-duplicate-in-array/
 * 
 * Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
 * There is only one repeated number in nums, return this repeated number.
 * You must solve the problem without modifying the array nums and uses only constant extra space.
 * 
 * Example 1:
 *   Input: nums = [1,3,4,2,2]
 *   Output: 2
 * Example 2:
 *   Input: nums = [3,1,3,4,2]
 *   Output: 3
 * Example 3:
 *   Input: nums = [1,1]
 *   Output: 1
 * Example 4:
 *   Input: nums = [1,1,2]
 *   Output: 1
 * 
 * Explained Solution:: 
 *  > Good Explaination on why Cycle detection works here and it's proof -> https://www.keithschwarz.com/interesting/code/?dir=find-duplicate
 *  > https://leetcode.com/problems/find-the-duplicate-number/discuss/72846/My-easy-understood-solution-with-O(n)-time-and-O(1)-space-without-modifying-the-array.-With-clear-explanation./75491
 *  > (Comment on Considering a Node)->https://leetcode.com/problems/find-the-duplicate-number/discuss/72845/Java-O(n)-time-and-O(1)-space-solution.-Similar-to-find-loop-in-linkedlist./260750
 *  > All solutions to this problem:
 *      https://leetcode.com/problems/find-the-duplicate-number/discuss/705111/summary-7-solutions-%2B-consice-explanation-and-complexity-analysis
 * 
 * Approach::
 *  > O(N)-time & O(1)-Space:
 *      >> The idea here is to consider a mapping function such that f(i) = A[i], this fuction maps the result onto itself(i.e. the array elements).
 *          Thus each index maps to a value A[i] that will map to another index. Now if all elements are distinct then the function would map all 
 *          unique values. And if we have two values that are duplicate then they will map to the same value. It will be something of the form::
 *                          x_0 -> x_1 -> ... x_k -> x_{k+1} ... -> x_{k+j}
 *                                             ^                       |
 *                                             |                       |
 *                                             +-----------------------+
 *          Hence, there will be a cycle formation that can be detected using Flyod's Cycle detection algorithm.
 * 
 *      >> For time complexity see: https://www.keithschwarz.com/interesting/code/?dir=find-duplicate
 * 
 * 
 **/
int findDuplicate(vector<int>& nums) {
    
    int n = nums.size()-1; // here there are n unique elements and 1 duplicate element and all elements are within [1, n] range( both inclusive ) 
    
    if(nums.size() <= 1){
        return -1;
    }
    
    int slow = nums[0]; // moves at 1x speed
    int fast = nums[nums[0]]; // moves at 2x speed
    
    // find the meeting point.
    while( slow != fast){
        slow = nums[slow];
        fast = nums[nums[fast]];
    }
    
    // find the duplicate element
    slow = nums[0];
    fast = nums[fast];
    while(slow != fast){ 
        slow = nums[slow];
        fast = nums[fast];
    }
    
    return slow;
}


int main() {
	vector<int> nums;
	int temp;
	while(cin>>temp){
	    nums.push_back(temp);
	}
	cout<<findDuplicate(nums)<<"\n";
	return 0;
}

