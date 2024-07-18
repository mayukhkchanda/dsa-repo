#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/** Question:: https://leetcode.com/problems/subarray-sum-equals-k/
 *  Given an array of integers(contains both negative and positive integers) nums and an integer k, 
 *   return the total number of continuous subarrays whose sum equals to k.
 *       Example 1:
 *           Input: nums = [1,1,1], k = 2
 *           Output: 2
 *       Example 2:
 *           Input: nums = [1,2,3], k = 3
 *           Output: 2
 *       Example 3:
 *           Input: nums = [1,-1,0], k = 3
 *           Output: 0
 * 
 *  Approach::
 *      > Calculate the prefix sum of every index. Prefix sum is the sum of every element from start of the array upto that element.
 *          Prefix sum of array for every element in array->[1,2,3] is PS->[1,3,6]
 *      > Now the sum of elements of sub-array from index i to j is PrefixSum(j)-PrefixSum(i-1) where i<j. 
 *          If this sum is equal to target we've found our sub-array.
 *      > So, we iterate over every index, calculate the prefix sum. We check if there's a prefix sum with value
 *          target-prefix_sum(i)[i is the current index]. 
 *      > Since, there can be multiple such sum's we store all of their count in the hashmap with the sum as the key.
 *      > We add those to our final count of answers.
 * 
 *  Time & Space complexity :: O(N) 
 * */

int subarraySum(vector<int>& nums, int target) {
    
    // will store the prefix sum and their respectiver count in this hashmap
    unordered_map<int,int> prefixSumMap;
    
    // the prefix sum upto index i
    int currentPrefixSum =0 ;
    
    // number of sub-arrays matching target sum
    int numSubArrays = 0;
    
    // iterate over the array and calculate the prefix sums at every index
    for (int i=0 ; i<nums.size() ; i++) {
        
        // include this element in our prefix sum
        currentPrefixSum+= nums[i];
        
        // if this sum itself matches the target sum then we have found
        // a sub-array starting from 0 to i
        if(currentPrefixSum == target ){
            numSubArrays++;
        }
        
        //if target-PrefixSum(i) exists then atleast 1 sub-array with the target sum exists.
        //And we are storing the count of all PrefixSum in hashmap as there can be multiple such sums.
        //Hence, we can add those count to the final answer
        if( prefixSumMap.find(currentPrefixSum-target) != prefixSumMap.end() ){
            numSubArrays+= prefixSumMap.at(currentPrefixSum-target);
        }
        
        // If the current prefix sum is not seen  before, insert it and mark it's count as 1
        if(prefixSumMap.find(currentPrefixSum) == prefixSumMap.end()){
            prefixSumMap.insert({currentPrefixSum,1});
        }else{
            // increment the prefix sum's count
            prefixSumMap[currentPrefixSum]++;
        }
    }
    
    return numSubArrays;
}

int main() {
	
// 	vector<int> array{1,2,3};
// 	int target = 3;
	
	// vector<int> array{2,2,3};
	// int target = 3;

//  vector<int> array{1,1,1};
// 	int target = 2;
	
// 	vector<int> array{0,0,3};
// 	int target = 3;

//  vector<int> array{1,-1,0};
// 	int target = 0;

    vector<int> array{28,54,7,-70,22,65,-6};
    int target = 100;
	
	cout<<subarraySum(array, target)<<"\n";
	
	return 0;
}
