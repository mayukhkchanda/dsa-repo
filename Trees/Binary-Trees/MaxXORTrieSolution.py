# Q: https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/
# Discussion: https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/discuss/91059/Java-O(n)-solution-using-Trie/275175

class Node:
    def __init__(self, bit):
        self.bit = bit
        self.bitMap = [None] * 2

class Solution:
    root = None
    
    
    def findMaximumXOR(self, nums: List[int]) -> int:
        self.root = Node(-1)
        
        res = 0
        
        for n in nums:
            temp = self.root
            for i in range(30, -1, -1):    
                bit = (n>>i)&1
                if temp.bitMap[bit] is None:
                    temp.bitMap[bit] = Node(bit)
                temp = temp.bitMap[bit]
            
        for n in nums:
            
            curr_max = 0
            temp = self.root
            
            for i in range(30, -1, -1):
                bit = (n>>i)&1 # get the ith bit of n
                other_bit = 0 if bit else 1
                
                if temp.bitMap[other_bit] is not None:
                    curr_max = curr_max ^ (1<<i)
                    temp = temp.bitMap[other_bit]
                else:
                    temp = temp.bitMap[bit]
            res = max(res, curr_max)
        
        return res
        
        
        