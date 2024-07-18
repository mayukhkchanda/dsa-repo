# intuition range caching
# Discussion: https://leetcode.com/problems/increment-submatrices-by-one/solutions/3052675/python3-sweep-line-range-addition-w-visualization-clean-concise/?orderBy=most_votes 

class Solution(object):

    def rangeAddQueries(self, n, queries):
        # return self.rangeCaching1D(n, queries)
        return self.rangeCaching2D(n, queries)

    def rangeCaching2D(self, n, queries):
        """
        :type n: int
        :type queries: List[List[int]]
        :rtype: List[List[int]]
        """
        mat = []
        for i in range(0, n):
            mat.append([0] * n)
            
        for q in queries:
            r1, c1, r2, c2 = q[0], q[1], q[2], q[3]

            mat[r1][c1] += 1
            if r2 + 1 < n: mat[r2 + 1][c1] -= 1
            if c2 + 1 < n: mat[r1][c2 + 1] -= 1
            if r2 +1 < n and c2 + 1 < n: mat[r2 + 1][c2 + 1] += 1
        
        # prefix sum over rows
        for r in range(0, n):
            for c in range(1, n):
                mat[r][c] += mat[r][c-1]

        # prefix sum over cols
        for r in range(1, n):
            for c in range(0, n):
                mat[r][c] += mat[r-1][c]
    
        return mat
    
    def rangeCaching1D(self, n, queries):
        """
        :type n: int
        :type queries: List[List[int]]
        :rtype: List[List[int]]
        """
        mat = []
        for i in range(0, n):
            mat.append([0] * n)
            
        for q in queries:
            r1, c1, r2, c2 = q[0], q[1], q[2], q[3]

            # add 1 to the start of each row in the update sub-matrix
            # and use prefix sum to calculate the final sub-matrix
            for i in range(r1, r2+1):
                mat[i][c1] += 1
                if c2 < n-1: mat[i][c2+1] -= 1

        for r in range(0, n):
            for c in range(1, n):
                mat[r][c] += mat[r][c-1]

        return mat