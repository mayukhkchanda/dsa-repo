/**
 * Question: https://leetcode.com/problems/single-number-ii/
 * 
 * Given an integer array nums where every element appears three times except for one, 
 * which appears exactly once. Find the single element and return it.
 * You must implement a solution with a linear runtime complexity and use only constant extra space.
 * Example 1:
 *     Input: nums = [2,2,3,2]
 *     Output: 3
 * Example 2:
 *     Input: nums = [0,1,0,1,0,1,99]
 *     Output: 99
 * 
 * Solution Discussion:
 *  > Only Comment on solution that I understood:
 *       https://leetcode.com/problems/single-number-ii/discuss/43296/An-General-Way-to-Handle-All-this-sort-of-questions./42189
 * Intuition:
 *  > Design an operation like XOR. In XOR if 2 bits are same then the bit is reset. Here we are trying
 *      to design a simillar operation that resets the bit if there are k bits that are same that is
 *      1@1@1@...upto k terms = 0  where @ represents an operation like XOR(^) where 1^1 = 0. 
 *  > As the digits of a signed int are represented using 31 bits hence we can use 31 bit counter or
 *      an array of length 31 of ints and use it to set and reset bits in the final result(i.e. the 
 *      number that has less than k occurances).
 *  > We can traverse each bit(31 bits in total) of n numbers and calculate using array counter if the
 *      final result has this bit set or not.
 * */

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int n = nums.size();
        
        int counter[32] = {0}; // a counter that records single bit of a 32 bit number
        
        int k = 3; // number of times other numbers appear in the array
        
        // iterate over all the bits of the number from 0th bit to 31st bit
        for(int i=0; i<32; i++){
            
            for(int j : nums){
            
                // for each bit in the of the result(i.e. the single number) 
                // only the single number's bit(either 1 or 0) will matter.
                // All the numbers with k(=3) occurances should be canceled.
                // Thus like in XOR where if 2 bits are 1 then the result bit
                // gets canceled, we need an operation which resets the final bit to
                // 0 if there are k occurances. So that, the ith bit of the final
                // result will have only the contribuition of the single number and not
                // the numbers with k occurances.
                if( j & (1<<i) ){
                    counter[i] = (counter[i]+1)%k;
                }
            }
        }
        
        int result = 0;
        // finally construct the result
        for(int i=0; i<32; i++){
            if(counter[i]>0){
                result |= (1<<i);
            }
        }
        
        return result;
    }
};