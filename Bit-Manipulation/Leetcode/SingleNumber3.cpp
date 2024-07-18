/**
 * Question: https://leetcode.com/problems/single-number-iii
 * 
 * Given an integer array nums, in which exactly two elements appear only once and
 * all the other elements appear exactly twice. Find the two elements that appear
 * only once. You can return the answer in any order.
 * You must write an algorithm that runs in linear runtime complexity and uses only
 * constant extra space.
 * 
 * Example 1:
 *     Input: nums = [1,2,1,3,2,5]
 *     Output: [3,5]
 *     Explanation:  [5, 3] is also a valid answer.
 * Example 2:
 *     Input: nums = [-1,0]
 *     Output: [-1,0]
 * Example 3:
 *     Input: nums = [0,1]
 *     Output: [1,0]
 * 
 * Solution Discussion:
 *  > https://leetcode.com/problems/single-number-iii/discuss/68900/Accepted-C%2B%2BJava-O(n)-time-O(1)-space-Easy-Solution-with-Detail-Explanations
 * 
 * Intuition?Algorithm:
 *  > As every other number is repeated twice hence we can take XOR of all the numbers. 
 *      So the effective xor will be of the 2 unique numbers only.
 *  > As it is a XOR and 2 numbers are unique thus the set bits in xor will be the result of
 *      set bit in 1 number and unset bit in the other number. Thus we can use a mask that contains
 *      any arbitary set bit of the XOR. 
 *  > We can take the xors of all the numbers that have the bit set and the numbers that have the bit
 *      unset. Thus these 2 xors will contain the unique numbers.
 * 
 * */

class Solution {
    
    int posLeftmostBit(int xr){
        
        int pos = 0;
        for(int i=0; i<32; i++){
            if(xr&(1<<i)) return i;
        }
        return -1;
    }
    
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        int n = nums.size();
        
        int xr = 0;
        
        // take xor of all numbers 
        for(int j: nums){
            xr ^= j;
        }
        
        // as 2 numbers are different thus a set bit means one of
        // them will have the bit set and the other one will have the bit unset.
        // So we find an arbitary set bit in the xor(here considering the leftmost bit)
        int i = posLeftmostBit(xr);
        
        int num1 = 0; // xor of all numbers that have the ith bit set
        int num2 = 0; // xor of all numbers that have theith bit unet
        
        for(int j: nums){
            
            if( j&(1<<i) ){
                num1 ^= j;
            }else{
                num2 ^= j;
            }
            
        }
        
        return {num1, num2};
    }
};