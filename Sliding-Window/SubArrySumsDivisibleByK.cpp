/**
 * Question: https://leetcode.com/problems/subarray-sums-divisible-by-k/
 * 
 * Given an integer array nums and an integer k, return the number of non-empty subarrays
 * that have a sum divisible by k. A subarray is a contiguous part of an array.
 * 
 * Example 1:
 *     Input: nums = [4,5,0,-2,-3,1], k = 5
 *     Output: 7
 *     Explanation: There are 7 subarrays with a sum divisible by k = 5:
 *     [4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]
 * Example 2:
 *     Input: nums = [5], k = 9
 *     Output: 0
 * 
 * Explained Solution:
 *  > https://leetcode.com/problems/subarray-sums-divisible-by-k/discuss/413234/DETAILED-WHITEBOARD!-BEATS-100-(Do-you-really-want-to-understand-It)
 * 
 * */

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        unordered_map<int, int> hashmap; // prefix%k and it's frequency
        hashmap.insert({0, 1});
        
        int prefix = 0;
        
        int total = 0;
        
        for(int i=0; i<n; i++){
            prefix = (prefix + nums[i])%k;
            
            if(prefix < 0) prefix += k;
            
            if(hashmap.find(prefix%k) != hashmap.end()){
                total += hashmap[prefix%k];
            }
            
            hashmap[prefix%k]++;            
        }
        
        return total;
    }
};