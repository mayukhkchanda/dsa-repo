# Question: https://leetcode.com/problems/minimum-cost-to-make-array-equal
# https://leetcode.com/problems/minimum-cost-to-make-array-equal/discuss/2734162/JavaC%2B%2BPython-Binary-Search

# The final equal number must be a number in the range of [min(nums), max(nums)]
#(Note: It cannot be outside this range, as in that case an extra number in nums
# need to be changed rather if it were picked from the range, thus increasing the cost)

# Hence the min cost of making all elements equal is res = f(x) for x in range 
# [min(nums), max(nums)], where x is the final equal element and f is the function to 
# calculate cost.

# Since, this a convex function, we can use binary search over the range [min(nums), 
# max(nums)] to find the element for which f(x) is minimum


class Solution:
    
    def f(self, nums, cost, target):
        res = 0
        for i in range(0, len(nums)):
            res = res + abs((nums[i]-target) * cost[i])
        return res
    
    def minCost(self, nums: List[int], cost: List[int]) -> int:
        left = min(nums)
        right = max(nums)
        
        res = self.f(nums, cost, left)
        
        while left < right:
            mid = left + (right - left) // 2
            
            cMid, cMidPlus1 = self.f(nums, cost, mid), self.f(nums, cost, mid + 1)
            
            res = min(cMid, cMidPlus1)
            
            if cMid < cMidPlus1:
                right = mid
            else:
                left = mid + 1
        
        return res