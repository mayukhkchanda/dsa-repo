/**
 * Question: https://leetcode.com/problems/k-closest-points-to-origin/
 * 
 * Solution & Explaination: https://leetcode.com/problems/k-closest-points-to-origin/discuss/660317/C%2B%2BJavaPython-2-solutions%3A-Max-Heap-MinHeap-Clean-code-O(NlogK)
 * 
 */
 class Comparator{
    public:
    bool operator()(vector<int> const &a, vector<int> const &b){
        return ( a[0]*a[0] + a[1]*a[1] ) < ( b[0]*b[0] + b[1]*b[1] );        
    }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        int n = points.size();
        vector<vector<int>> res = {};
        
        if(k > n) return res;
        
        priority_queue< vector<int>, vector<vector<int>>, Comparator > maxHeap;
        for(auto p : points){
            maxHeap.push(p);
            if( maxHeap.size() > k ){
                maxHeap.pop();
            }
        }
        
        while( k>0 && !maxHeap.empty() ){
            res.push_back(maxHeap.top());
            maxHeap.pop();
            k--;
        }
        
        return res;
    }
};