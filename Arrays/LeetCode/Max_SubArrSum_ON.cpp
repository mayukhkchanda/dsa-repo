#include<iostream>
#include<vector>
#include<climits>
using namespace std;

// https://leetcode.com/problems/maximum-subarray

/*
 * Given an integer array nums, find the contiguous subarray (containing at least one number) 
 * which has the largest sum and return its sum.
 * 
 * Example 1:
 * 
 * Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
 * Output: 6
 * Explanation: [4,-1,2,1] has the largest sum = 6.
 * */

//start iterating each index of the array and start a subarray from 0th index
//if at an index the sum is greater than 0, only then continue adding the current element
//else we are better of ditching the currently running sub-array and starting a new sub-array
//from the current index.
//we store the sum and maxSubarraySum as the max of 0 and current sum
//!!NOTE!! only have maxSubarraySum as 0 if 0 is allowed as a return value else initialise max as INT_MIN

int maxSubarraySum(vector<int> arr){
    int n = arr.size();
    
    // initially sum is -INFINITY
    int sum = INT_MIN;
    
    int maxSum = 0;
    
    for(int i=0;i<n;i++){
        //if the sum is > 0 then continue adding
        //else start a new sub-array from this index
        sum = sum > 0 ? sum+arr[i] : arr[i];
        maxSum = max(maxSum, sum);
    }
    
    return maxSum;
}

int main() {
	// your code goes here
	cout<<maxSubarraySum({-1,2,3,4,-2,6,-8,3})<<"\n";
	return 0;
}
