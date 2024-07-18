#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <set>
using namespace std;

/**
 * Question:: https://www.interviewbit.com/problems/maximum-sum-triplet/
 * Given an array of positive integers of size n. Find the maximum sum of triplet( ai + aj + ak ) such that 0 <= i < j < k < n and ai < aj < ak. 
 * 
 * Example::
 *   Input: a[] = 2 5 3 1 4 9
 *   Output: 16
 *   
 *   Explanation:
 *   All possible triplets are:-
 *   2 3 4 => sum = 9
 *   2 5 9 => sum = 16
 *   2 3 9 => sum = 14
 *   3 4 9 => sum = 16
 *   1 4 9 => sum = 14
 *   Maximum sum = 16
 * 
 * Explained Solution:: https://www.geeksforgeeks.org/find-maximum-sum-triplets-array-j-k-ai-aj-ak/
 * 
 * Approach:: 
 *  > ON^3 - use 3 nested loops to check for every possible triplet in the array.
 *  > ON^2 - Use 2 loops. The outer loop iterates over every element and considers it the middle element of the triplet.
 *          Thus the inner loop can be used to find the maximum element to the left and right of this element such that both are greater
 *          than the middle element.
 *  > ONlogN-time & ON-space ::
 *      >> Compute all the maximum elements that are to the right of element i for every element in the array.
 *      >> Have a sorted set that stores the elements from 0 to i-1 in sorted manner such that binary search can be applied to it. Start iterating
 *          over the array fro 1 to n-1 and consider each element as the middle element. Find using Binary search the maximum element in this sorted 
 *          set which is strictly less than the current element. 
 *      >> If both maximum in left and right are greater than the current element then we can consider this triplet. 
 *      >> Finally compute the maximum of all such triplets.
 * 
 * 
 * */


int getLeftMaxElement(set<int> container, int target){
    
    // returns iterator to the first element greater than or equal to target
    auto itr = container.lower_bound(target);
    
    // as we need the maximum element that is strictly less than target we return the 
    // 1 previous element to itr.
    return itr != container.begin() ?  *(--itr) : -1;
    
}


int findMaxTripletSum(vector<int> &array){
    
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


int main() {
	
	int temp;
	vector<int> A;
	
	while(cin >> temp){
	    A.push_back(temp);
	}
	
	cout<< findMaxTripletSum(A) ;
	
	return 0;
}
