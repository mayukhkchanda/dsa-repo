/**
 * Question: https://practice.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1#
 * 
 */
 
 class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        
        priority_queue<long long, vector<long long>, greater<long long>> minHeap;
        
        for(long long i=0; i<n; i++) minHeap.push(arr[i]);
        
        long long total = 0;
        
        while( minHeap.size() > 1 ){
            long long r1 = minHeap.top();
            minHeap.pop();
            
            long long r2 = minHeap.top();
            minHeap.pop();

            total += (r1+r2);
            
            minHeap.push(r1+r2);
        }
        return total;
    }
};
