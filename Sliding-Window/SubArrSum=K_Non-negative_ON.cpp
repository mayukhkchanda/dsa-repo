#include <iostream>
#include <vector>
using namespace std;

/**Question:: https://practice.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1#
 *  Given an unsorted array A of size N that contains only non-negative integers, 
 *  find a continuous sub-array which adds to a given number S.
 *    Example 1:
 *    Input: N = 5, S = 12, A[] = {1,2,3,7,5}
 *    Output: 2 4[indexed-1]
 *    Explanation: The sum of elements from 2nd position to 4th position is 12.
 * 
 *  Approach::
 *      > We use 2 pointers and sliding window for this problem.
 *      > We have 2 pointers starting from 0th index and a 'sum' that stores the sum of the elements in the window.
 *      > We start expanding the window by incrementing the right pointer by 1 index. 
 *      > If the sum is less than target we expand the window again.
 *      > Else if the sum is greater than the target we contract the window by shrinking the left side 
 *        of the window that is we increment the left pointer until the sum is less than target. 
 *      > If the sum matches the target value, we found a sub-array whose sum add up to the target.
 *      > We do this until the right pointer hits the last index.
 *      > We perform some clean-up operations i.e. if the left pointer has not yet reached the last index
 *        we increment the left pointer by 1 until the last index and keep substracting the each element from
 *        the sum. If the sum becomes equal to the target, we found a pair that would have been skipped otherwise.
 *      > We can return all the index pairs or their count.
 * 
 *      !!NOTE:: This will not work for an array containing negative numbers!!
 *      Good Article on Sliding window and 2 pointer and the scenerios where they work ane where they donot:-
 *      https://leetcode.com/problems/subarray-sum-equals-k/discuss/301242/General-summary-of-what-kind-of-problem-can-cannot-solved-by-Two-Pointers
 * 
 * */

// Find the number of sub-arrays with the target sum
int subarraySum(vector<int>& nums, int target) {
    int i=0; //left pointer -> start of window
    int j=0; //right pointer -> end of window
    
    int n=nums.size();
    
    // the sum of all elements in the current window
    int runningSum = 0;
    
    // vector containing the sub-array indexes to be returned
    vector<pair<int,int>> subArrayIndexes;
    
    // while the right pointer has not yet reached the end
    while(j<n){
        
        // include the current element in the window
        runningSum+=nums[j];
        
        // if the window sum becomes greater than target sum
        // we need to contract the window as all elements are positive
        while(i<j && runningSum > target){
            runningSum -= nums[i];
            i++;
        }
        
        // if the window sum matches the target sum we found a sub-array
        // both i & j are inclusive
        if(runningSum == target){
            subArrayIndexes.push_back({i,j});
        }
        
        j++;
    }
    //bring j to the last index
    j--;
    while(i<j){
        
        runningSum -= nums[i];
        i++;
        
        if(runningSum == target){
            subArrayIndexes.push_back({i,j});
        }
    }
    return subArrayIndexes.size();
}


// Find the smallest sub-array in terms of length whose sum is equal to target
pair<int,int> smallestSubarrayWithSum(vector<int>& nums, int target) {
    int i=0; //left pointer/window start index
    int j=0; //right pointer/window end index
    
    int n=nums.size();
    
    int runningSum = 0; 
    
    pair<int,int> smallestSubArr={0,n}; //any sub-array in the array will be smaller than size of the array
    
    //till the window end reaches the last index
    while(j<n){
        
        //include the current element in the window and expand the size
        runningSum+=nums[j];
        
        //if the sum becomes greater than the target, contract the window's size
        while(i<j && runningSum > target){
            runningSum -= nums[i];
            i++;
            
        }
        
        //if the sum is equal to the target we found a pair
        if(runningSum == target){
            
            //if this sub-array is smaller in length then consider it
            if(smallestSubArr.second-smallestSubArr.first > j-i){
                smallestSubArr = {i,j};
            }
        }
        
        j++;
    }
    //bring j to the last index
    j--;
    
    //check if window size is not 0, then contract the window's size and check if any sub-array matches target sum
    while(i<j){
        
        runningSum -= nums[i];
        i++;
        
        if(runningSum == target){
            
            if(smallestSubArr.second-smallestSubArr.first > j-i){
                smallestSubArr = {i,j};
            }
        }
        
    }
    
    return smallestSubArr;
}

int main() {
// vector<int> array{1,1,1};
// int target =2;
   vector<int> array{1,-1,0};
   int target =0;
// vector<int> array{1,2,3};
// int target =3;
// vector<int> array{28,54,7,-70,22,65,-6};
// int target = 100;
// vector<int> array{1,3,2,1,4,1,3,2,1,1};
// int target = 8;
	

	cout<<subarraySum(array, target )<<"\n"; //finding how many sub-arrays exists with the target sum

    pair<int,int> smallestSubArr = smallestSubarrayWithSum(array, target); //finding the smallest sub-array with the target sum
	cout<<smallestSubArr.first<<" "<<smallestSubArr.second<<"\n";
	
	return 0;
}
