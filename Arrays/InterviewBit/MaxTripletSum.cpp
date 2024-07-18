/*
https://www.interviewbit.com/problems/maximum-sum-triplet/

Given an array A containing N integers.
You need to find the maximum sum of triplet ( Ai + Aj + Ak ) such that 0 <= i < j < k < N and Ai < Aj < Ak.
If no such triplet exist return 0.

Example Input
    Input 1: A = [2, 5, 3, 1, 4, 9]
    Input 2: A = [1, 2, 3]

Example Output
    Output 1: 16
    Output 2: 6

Example Explanation
    Explanation 1:
    All possible triplets are:-
        2 3 4 => sum = 9
        2 5 9 => sum = 16
        2 3 9 => sum = 14
        3 4 9 => sum = 16
        1 4 9 => sum = 14
    Maximum sum = 16
Explanation 2:
    All possible triplets are:-
        1 2 3 => sum = 6
    Maximum sum = 6

GFG Explanation: https://www.geeksforgeeks.org/find-maximum-sum-triplets-array-j-k-ai-aj-ak/

*/


int getLeftMaxElement(set<int> container, int target){
    
    // returns iterator to the first element greater than or equal to target
    auto itr = container.lower_bound(target);
    
    // as we need the maximum element that is strictly less than target we return the 
    // 1 previous element to itr.
    return itr != container.begin() ?  *(--itr) : -1;
    
}


int Solution::solve(vector<int> &array){
    
    int n = array.size();
    
    int maxRightElement[n] = {-1};
    
    // computing the suffix array for maximum element to the right 
    // of ith element
    for (int i = n-2; i>=0 ; i--) {
        maxRightElement[i] = max(maxRightElement[i+1], array[i+1]);
    }
    
    // holds the element from 0 to i-1 in a sorted manner such that binary search can be applied to it
    // to fint the maximum element smaller than i.
    set<int> sortedSubList;
    
    sortedSubList.insert(array[0]);
    
    int maxTripletSum = 0;
    
    // consider i as the middle element and find the maxRightElement strictly greater than this element(stored in suffix array)
    // and perform a lower bound search on the sortedSubList for the maximum element to the left of sub-list that is smaller
    // than ith element.
    for (int i = 1; i < n-1; i++) {
        
        int max_to_right = maxRightElement[i];
        int max_to_left = getLeftMaxElement(sortedSubList, array[i]);
        
        if(max_to_left < array[i] && array[i] < max_to_right){
            maxTripletSum = max(maxTripletSum, max_to_left+array[i]+max_to_right);
        }
        
        sortedSubList.insert(array[i]);
    }
    
    return maxTripletSum;
}
