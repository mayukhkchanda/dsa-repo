# Q: https://leetcode.com/problems/word-pattern
#    https://leetcode.com/problems/isomorphic-strings/
# Both the above questions have simillar Solutions discussed below
# Solution:
# > https://leetcode.com/problems/word-pattern/discuss/73402/8-lines-simple-Java

class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        
        s_hashmap = {}
        t_hashmap = {}
        
        for i in range(0, len(s)):
            
            if s[i] not in s_hashmap.keys():
                s_hashmap[s[i]] = i
            
            if t[i] not in t_hashmap.keys():
                t_hashmap[t[i]] = i
            
            if s_hashmap[s[i]] != t_hashmap[t[i]]:
                return False
        
        return True
        