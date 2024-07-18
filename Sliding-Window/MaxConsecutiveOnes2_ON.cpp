#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

/**
 * Question::https://leetcode.com/problems/max-consecutive-ones-iii/
 * 
 * Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.
 * 
 * Example 1:
 *   Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
 *   Output: 6               -------------
 *   Explanation: [1,1,1,0,0,|1,1,1,1,1,1|]
 *   Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
 * Example 2:
 *   Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
 *   Output: 10        ---------------------    
 *   Explanation: [0,0,|1,1,1,1,1,1,1,1,1,1|,0,0,0,1,1,1,1]
 *   Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
 * 
 * 
 * Similar Question and Approach as this post::
 *  > https://leetcode.com/problems/longest-repeating-character-replacement/discuss/91285/Sliding-window-similar-to-finding-longest-substring-with-k-distinct-characters
 * More similar types of questions::
 *  > https://leetcode.com/problems/max-consecutive-ones-iii/discuss/247564/JavaC%2B%2BPython-Sliding-Window
 * 
 * Approach::
 *  > This is similar to the "longest-repeating-character-replacement" leetcode question.
 *  > Here, if k was not given as an upper limit then we would have changed all the 0's to 1's.
 *      But with k as an upper limit we could only change atmost k 0's.
 *  > Hence we use the sliding window approach discussed in the post. The window is considered
 *      to be valid only if the number of 0's we have in that window is less than or equal to  k.
 *      Thus we store the maximum length of a valid window while computing all such valid windows.
 *  
 * */


int longestOnes(vector<int>& nums, int k) {
    
    int n = nums.size();
    
    int left = 0;
    int right = 0;
    
    // stores the number of 1's in each window
    int count_zeros = 0;
    
    int maxOnes = INT_MIN;
    
    while(right < n){
        
        // increase the count of zeros if a 0 is spotted in this window
        count_zeros += !nums[right] ? 1 : 0;
        
        // if due to inclusion of this 0's the window became invalid then
        // we shrink the window till it's valid again.
        while( count_zeros > k ){
            count_zeros -= !nums[left] ? 1 : 0;
            left++;
        }
        
        // we store the maximum length of subarray that of a valid window.
        // here we use <= k as we can change less than or equal to k 0's only.
        if(count_zeros <= k){
            maxOnes = max(maxOnes, right-left+1);
        }
        
        right++;
    }
    
    // finally return the maxOnes that we can get from a valid window
    return maxOnes;
}

int main() {
	
	int k;
	cin >> k;
	
	vector<int> nums;
	int temp;
	while(cin >> temp) nums.push_back(temp);
	
	cout<< longestOnes(nums, k)<<"\n";
	
	
	return 0;
}
