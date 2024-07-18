#include <iostream>
#include <vector>
using namespace std;

/**
 * Question:: https://leetcode.com/problems/find-peak-element/
 * 
 * A peak element is an element that is strictly greater than its neighbors.
 * 
 * Given an integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.
 * You may imagine that nums[-1] = nums[n] = -∞.
 * You must write an algorithm that runs in O(log n) time.
 * 
 * Example 1:
 *   Input: nums = [1,2,3,1]
 *   Output: 2
 *   Explanation: 3 is a peak element and your function should return the index number 2.
 * 
 * 
 * Links::
 *   > Solution -> https://leetcode.com/problems/find-peak-element/discuss/50232/Find-the-maximum-by-binary-search-(recursion-and-iteration)
 *   > Explanation of why and how this process works:: https://leetcode.com/problems/find-peak-element/discuss/50232/Find-the-maximum-by-binary-search-(recursion-and-iteration)/186496
 *   > Another approach:: https://leetcode.com/problems/find-peak-element/discuss/1290642/intuition-behind-conditions-complete-explanation-diagram-binary-search
 * 
 * Notes::
 *   > This problem is similar to -> https://leetcode.com/problems/peak-index-in-a-mountain-array/
 *   > Solution to above question ->https://leetcode.com/problems/peak-index-in-a-mountain-array/discuss/139848/C%2B%2BJavaPython-Better-than-Binary-Search
 * 
 * Approach::
 *   > Above links explain the solution clearly. 
 *   > We are trying to converge our answer here to a single peak index it can be any peak.
 *   > The cases that determine the if-else condition are discussed below::
 *      1. A[mid] < A[mid+1] => mid lies in the increasing slope. We do left <- mid+1 as A[mid+1] > A[mid], so mid can never be the peak index
 *      2. A[mid] > A[mid+1] => either mid is the peak index or mid lies in the decreasing slope. In either case we cannot eliminate mid element
 *                              itself as mid element can be the peak index. So we put right <- mid.
 *  
 *  !!Note -> There are 2 reasons why binary search works::
 *      
 *      >> Both the sides of array have INT_MIN as the terminal. This means that even if you keep throwing half of the array in each search. 
 *          You will always end up in one of the corner
 *        1a. You will reach first element with second number smaller than it
 *        1b. OR you will reach last element with second last element smaller than it
 *            In both the cases the answer will be either the first or the last element respectively since its sure they have INT_MIN on the other side
 *      
 *      >> No two adjacent elements are same.!!
 *      >> This comment explains the scenarios and why they work-> https://leetcode.com/problems/find-peak-element/discuss/50232/Find-the-maximum-by-binary-search-(recursion-and-iteration)/186496
 *   
 * 
 * 
 * */

// returns the index of the peak element in the array
int findPeak(vector<int> &array){
    
    int left = 0;
    int right = array.size()-1;


    while(left < right){

        int mid = left + (right-left)/2;
        
        // if A[m] < A[m+1] -> l = m+1 (Since m is smaller than m+1, m will for sure be not the answer)
        if(array[mid] < array[mid+1]){
            left = mid+1;
        }
        // else A[m] > A[m+1] -> r=m (Not m-1 since m is larger and it itself can be the answer)
        else{
            right = mid;
        }
    }
    
    // finally left and right will converge to a peak index 
    return left;
}


int main() {
    
    vector<int> array;
    
    int temp;
    
    while(cin >> temp){
        array.push_back(temp);
    }
    
    cout<< findPeak(array);
    
	return 0;
}

