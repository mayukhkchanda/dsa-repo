/**
 * Question: https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/
 * 
 * Given an integer array nums, return the maximum result of nums[i] XOR nums[j], where 0 <= i <= j < n.
 * Example 1:
 *     Input: nums = [3,10,5,25,2,8]
 *     Output: 28
 *     Explanation: The maximum result is 5 XOR 25 = 28.
 * Example 2:
 *     Input: nums = [0]
 *     Output: 0
 * Example 3:
 *     Input: nums = [2,4]
 *     Output: 6
 * Example 4:
 *     Input: nums = [8,10,2]
 *     Output: 10
 * Example 5:
 *     Input: nums = [14,70,53,83,49,91,36,80,92,51,66,70]
 *     Output: 127
 * 
 * Solution Intuition and Discussion:
 *  > Post Commnet -> https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/discuss/91049/Java-O(n)-solution-using-bit-manipulation-and-HashMap/95581
 * 
 * Intuition:
 *  > We traverse n number consider each single bit at a time starting from the most significant bit.
 *      Then we check each bit from MSB to LSB if that bit could be set in the final bit. For this,
 *      we first extract the first i bits starting from the msb of each number. Then we used set this
 *      i-th bit in a the max variable. Now we need to find two number from the extracted left part 
 *      of the numbers such that A^B = max_with_ith_set_bit. As A^B = c => A = B^C, thus we check 
 *      for each number, if their extracted left part^max_with_ith_set_bit exists in the set of
 *      extracted lef part of the numbers. If such a number exits then we finally set the bit in the
 *      result else we unset the bit. 
 * 
 * */

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        
        int max = 0;
        
        int mask = 0;
        
        for(int i=30; i>=0; i--){
            
            mask = mask | (1<<i);
            
            unordered_set<int> hashset;
            
            // extract the left part of each number and put it in set.
            for(int i: nums){
                hashset.insert(i&mask);
            }
            
            // check if we can set this ith bit in the final result
            int greedyTry = max | (1<<i);
            
            for(int n : hashset){
                
                // try to find 2 numbers in the hashset such that x^y=greedyTry
                // for this we check if y^greedyTry exists in hashset.
                // As a^b=c => b=a^c.
                if(hashset.find(n^greedyTry) != hashset.end()){
                    // if it exists then we know this bit will be set in the final result
                    max = greedyTry;
                    break;
                }
            }
        }
        
        return max;
    }
};