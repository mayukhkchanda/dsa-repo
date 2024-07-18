#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * Question:: https://leetcode.com/problems/find-k-th-smallest-pair-distance/
 * 
 * Given an integer array nums and an integer k, return the kth smallest distance among all 
 * the pairs nums[i] and nums[j] where 0 <= i < j < nums.length.
 * The distance of a pair of integers a and b is defined as the absolute difference between a and b.
 * 
 * Example 1:
 *   Input: nums = [1,3,1], k = 1
 *   Output: 0
 *   Explanation: Here are all the pairs:
 *   (1,3) -> 2
 *   (1,1) -> 0
 *   (3,1) -> 2
 *   Then the 1st smallest distance pair is (1,1), and its distance is 0.
 * Example 2:
 *   Input: nums = [1,1,1], k = 2
 *   Output: 0
 * Example 3:
 *   Input: nums = [1,6,1], k = 3
 *   Output: 5
 * 
 * !! This question is similar to a series of question discussed in the posts below::
 *      ->https://leetcode.com/problems/koko-eating-bananas/discuss/769702/Python-Clear-explanation-Powerful-Ultimate-Binary-Search-Template.-Solved-many-problems.
 *      https://medium.com/swlh/binary-search-find-upper-and-lower-bound-3f07867d81fb
 *      https://www.topcoder.com/thrive/articles/Binary%20Search
 * 
 * Approach::
 *  > We try to find the number of pairs whose absolute difference is smaller than a given number in the nums array.
 *      For this we sort the array and use the algorithm discussed here -> https://stackoverflow.com/a/24710008
 *  > Now the function cntPairs is monotonous with respect to upperBound.  We can apply Binary search here to find the 
 *      minimum number such tha cntPairs(upperBound) >= k. As we are trying to find the kth smallest difference pair.
 * 
 * 
 * Time complexity -> O(NlogM) where N is # of elements in nums and M is the range form 0 to 10^6(as the maximum number in nums can be 10^6)
 * 
 * */

// returns the number of pairs such that the absolute difference b/w these 
// pairs is less than or equal to upperBound
int cntPairs( vector<int> nums, int upperBound ){
    
    int n = nums.size();
    
    int slow = 0;
    int fast = 1;
    
    int count = 0;
    
    // have 2 pointers slow and fast. move the fast pointer before the slow pointer
    // till we have the absolute difference b/w slow and fast elements <= upperBound.
    // As the array is sorted all of these numbers will form pairs such that the condition is statisfied.
    while(slow < n || fast < n ){
        
        while( fast < n && nums[fast] - nums[slow] <= upperBound ){
            fast++;
        }
        
        count += fast-slow-1;
        slow++;
    }
    return count;
}



int smallestDistancePair(vector<int>& nums, int k) {
    
    int n = nums.size();
    
    sort(nums.begin(), nums.end());
    
    int left = nums[1] - nums[0]; // minimum distance is the 2 smallest numbers are used 
    int right = nums[n-1] - nums[0]; // maximum distance is when first and last number are used
    
    
    while(left < right){
        
        int mid = left + (right - left)/2;
        
        // if there are less pairs than k in nums whose absolute difference is atmost mid
        // then anythnig from left to mid range cannot contain the absolute difference such that atleast
        // k pairs have less than this difference b/w them.
        if( cntPairs(nums, mid) < k ){
            left = mid+1;
        }else{
            right= mid;
        }
    }
    return left;
}


int main() {
	
	vector<int> nums;
	int k ;
	
	cin >> k;
	
	int temp;
	
	while(cin >> temp){
	    nums.push_back(temp);
	}
	
	cout<< smallestDistancePair(nums, k)<<"\n";

    // cout<< cntPairs(nums, 1);
	
	return 0;
}
