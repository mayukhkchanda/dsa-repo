/**
 * Question: https://leetcode.com/problems/subarrays-with-k-different-integers
 * 
 * Given an integer array nums and an integer k, return the number of good subarrays of nums.
 * A good array is an array where the number of different integers in that array is exactly k.
 * For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
 * A subarray is a contiguous part of an array.
 * 
 * Example 1:
 *     Input: nums = [1,2,1,2,3], k = 2
 *     Output: 7
 *     Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3],
 *                  [1,2,1], [2,1,2], [1,2,1,2]
 * Example 2:
 *     Input: nums = [1,2,1,3,4], k = 3
 *     Output: 3
 *     Explanation: Subarrays formed with exactly 3 different integers: [1,2,1,3], [2,1,3], [1,3,4].
 * 
 * Solution Discussion:
 *  > Main Idea Discussion(comment): https://leetcode.com/problems/subarrays-with-k-different-integers/discuss/235235/C++Java-with-picture-prefixed-sliding-window/251836
 *  > Post Discussion: https://leetcode.com/problems/subarrays-with-k-different-integers/discuss/235235/C%2B%2BJava-with-picture-prefixed-sliding-window
 * 
 * */

class Solution {
    
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        
        int left = 0;
        int right = 0;
        
        unordered_map<int, int> count;
        int uniques = 0;
        int repeatNums = 0;
        
        int cntArrs = 0;
        
        while(right < n){
            
            count[nums[right]]++; // increase the count of this number
            
            // increase count of unique  numbers
            if(count[nums[right]] == 1){
                uniques++;
            }
            
            // if including this number to the window make
            // count of uniques > k, then we need to shrink the window
            // and reset repeatNums to 0.
            if(uniques>k){
                count[nums[left]]--;
                uniques--;
                left++;
                repeatNums = 0;
            }
                        
            // if we see a duplicate occurance, then try 
            // to find the prefix of repeated nums by shrinking
            // the window from the left
            while(count[nums[left]] > 1){
                count[nums[left]]--;
                repeatNums++;
                left++;
            }
    
            // check if we have k unique numbers
            if(uniques == k){
                //if so then add repeatedNums+1 to the count
                cntArrs += repeatNums+1;
            }
            right++;
        }
        return cntArrs;    
    }
};