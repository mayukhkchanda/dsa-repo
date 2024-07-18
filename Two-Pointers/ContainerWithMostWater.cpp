/**
 * Question: https://leetcode.com/problems/container-with-most-water/
 * 
 * Given n non-negative integers a1, a2, ..., an , where each represents a point at 
 * coordinate (i, ai). n vertical lines are drawn such that the two endpoints of the 
 * line i is at (i, ai) and (i, 0). Find two lines, which, together with the x-axis 
 * forms a container, such that the container contains the most water.
 * Notice that you may not slant the container.
 * 
 * Example 1:
 *     Input: height = [1,8,6,2,5,4,8,3,7]
 *     Output: 49
 *     Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
 * Example 2:
 *     Input: height = [1,1]
 *     Output: 1
 * Example 3:
 *     Input: height = [4,3,2,1,4]
 *     Output: 16
 * Example 4:
 *     Input: height = [1,2,1]
 *     Output: 2
 * 
 * Solution Discussion:
 *  > https://leetcode.com/problems/container-with-most-water/discuss/6100/Simple-and-clear-proofexplanation
 * 
 * Intuition:
 *  > The widest container with using first and last line is idealy a good candidate(since we don't know
 *      at the starting how high the lines go). Thus we start with 2 pointers at the start and at the end.
 *      We check for each container if it has the max capacity using length of 2 lines and the width.
 *      We always move the pointer that points to the line with smaller height(arbitary choice if line 
 *      heights are equal) in hopes that we could find a line that has higher height.
 * */

class Solution {
public:
    int maxArea(vector<int>& nums) {
        int n = nums.size();
        
        int left = 0;
        int right = n-1;
        
        int res = 0;
        
        while(left < right){
            
            res = max(res, (right-left)*min(nums[left], nums[right]));
            
            if(nums[left] <= nums[right]){
                left++;
            }else{
                right--;
            }
        }

        return res;
    }
};
