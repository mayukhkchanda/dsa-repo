#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
using namespace std;

/**
 * Question:: 
 *  LC -> https://leetcode.com/problems/maximum-gap/
 *  IB -> https://www.interviewbit.com/problems/maximum-consecutive-gap/
 * 
 * Given an integer array nums, return the maximum difference between two !SUCCESSIVE! elements.
 * in its sorted form. If the array contains less than two elements, return 0.
 * You must write an algorithm that runs in linear time and uses linear extra space.
 * 
 * Example 1:
 *   Input: nums = [3,6,9,1]
 *   Output: 3
 *   Explanation: The sorted form of the array is [1,3,6,9], either (3,6) or (6,9) has the maximum difference 3.
 * 
 * Example 2:
 *   Input: nums = [10]
 *   Output: 0
 *   Explanation: The array contains less than 2 elements, therefore return 0.
 * 
 * 
 * 
 * Approach::
 *  > The approach here is based on Bucket sort technique. See links for clarification.
 *  > In bucket sort technique we have buckets that store values within a particular range.
 * 
 *      >> GFG article -> https://www.geeksforgeeks.org/bucket-sort-2/  
 * 
 *      >> The difference(gap) of each of the range's start and end value remains same that is 
 *         if we have our gap as G and the smallest element in the array is min , then the ith
 *         bucket will store values between the range [ Min+(G*i) , Min+(G*(i+1)) ) {start inclusive, end exclusive}.
 *     
 *      >> The elements in each bucket are not sorted but the buckets are sorted according to the ranges.
 * 
 * 
 * 
 * 
 * */


int maximumGap(vector<int>& nums) {

    int n = nums.size();

    if(n <= 2){
        return n==2? abs(nums[0]-nums[1]) : 0;
    }

    int Min = INT_MAX;
    int Max = INT_MIN;

    for (auto i : nums) {
        Min = min(Min, i);
        Max = max(Max, i);
    }

    if(Min == Max){
        return 0;
    }

    int min_gap = ceil( (float)(Max-Min)/(float)(n-1) );
    
    int bucket_size = (Max-Min)/(min_gap);
    
    vector<int> bucketMin(bucket_size+1, INT_MAX);
    vector<int> bucketMax(bucket_size+1, INT_MIN);

    for (int i = 0; i < n; i++) {
        int bucketIndx = (nums[i]-Min)/min_gap;

        bucketMin[bucketIndx] = min(bucketMin[bucketIndx], nums[i]);
        bucketMax[bucketIndx] = max(bucketMax[bucketIndx], nums[i]);
    }

    int maxDiff = INT_MIN;
    int previous = Min;

    for (int i = 0; i < bucketMax.size(); i++) {

        if(bucketMax[i] == INT_MIN){
            continue;
        }

        maxDiff = max(bucketMin[i]-previous, maxDiff);
        previous = bucketMax[i];
    }


    return maxDiff;
}

int main() {
	vector<int> nums;
	int temp;
	while(cin>>temp) nums.push_back(temp);
	
	cout<< maximumGap(nums) <<"\n";
	
	return 0;
}
